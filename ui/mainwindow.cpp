#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "glbox.h"
#include "properties.h"
#include "constants.h"

#include <QCloseEvent>
#include <QFileDialog>
#include <QMessageBox>
#include <QGraphicsScene>
#include <QGraphicsItem>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), texturesWindow(&doc, this), doc("LBlockML"), dirty(false), group(NULL)
{
	ui = new Ui::MainWindow;

	ui->setupUi(this);
	texturesWindow.show();

	scene = new QGraphicsScene;
	ui->graphicsView->setScene(scene);

	group.addAction(ui->actionWall);
	group.addAction(ui->actionFloor);
	group.addAction(ui->actionTable);

	connect(ui->actionTextures, SIGNAL(toggled(bool)), &texturesWindow, SLOT(setVisible(bool)));
	connect(&texturesWindow, SIGNAL(rejected()), ui->actionTextures, SLOT(toggle()));
	
	connect(this, SIGNAL(error(QString)), this, SLOT(slotErrorHandler(QString)));

	slotNew();
}

MainWindow::~MainWindow()
{
	delete ui;
	delete scene;
}

void MainWindow::clear()
{
	texturesWindow.refresh();

	QDomElement elem = doc.documentElement().toElement().elementsByTagName("properties").item(0).toElement();
	ui->floorNumber->setMinimum(elem.attribute("lowest", "0").toInt());
	ui->floorNumber->setMaximum(elem.attribute("highest", "0").toInt());
	ui->floorNumber->update();

	int grid = elem.attribute("grid", "10").toInt();
	int length = elem.attribute("length", "60").toInt();
	int width = elem.attribute("width", "40").toInt();

	if (! itemsList.isEmpty()) {
		qDeleteAll(itemsList);
		itemsList.clear();
	}

	scene->clear();
	scene->setSceneRect(0, 0, length * PIXELS_PER_FOOT, width * PIXELS_PER_FOOT);

	QPen pen = QPen(Qt::lightGray);
	pen.setStyle(Qt::DashLine);

	{
		int tmp = width * PIXELS_PER_FOOT;
		for (int i = grid; i < length; i+= grid) {
			int tmp2 = i * PIXELS_PER_FOOT;
			scene->addLine(tmp2, 0, tmp2, tmp, pen);
		}
	}

	{
		int tmp = length * PIXELS_PER_FOOT;
		for (int i = grid; i < width; i+= grid) {
			int tmp2 = i * PIXELS_PER_FOOT;
			scene->addLine(0, tmp2, tmp, tmp2, pen);
		}
	}

	dirty = true;
	slotMakeClean();
}

void MainWindow::slotNew()
{
	if (! okToClose())
		return;

	filename.clear();
	doc.setContent(QString(
"<!DOCTYPE LBlockML>\n"
"<lblock>\n"
" <properties/>\n"
" <textures/>\n"
" <floors>\n"
"  <floor id=0>\n"
" </floors>\n"
"</lblock>\n"));
	slotShowFloor(0);
}

void MainWindow::slotOpen()
{
	if (! okToClose())
		return;

	QString name = QFileDialog::getOpenFileName(this, "Open File...", QString(), "LBlockML files (*.lml)");

	if (name.isEmpty())
		return;

	filename = name;

	QFile file(name);
	doc.setContent(&file);
	file.close();

	clear();

	int floor = doc.documentElement().elementsByTagName("properties").item(0).toElement().attribute("id").toInt();
	slotShowFloor(floor);
}

void MainWindow::slotSave()
{
	if (filename.isEmpty())
		slotSaveAs();

	QByteArray array = doc.toByteArray();

	QFile file(filename);

	if (! file.open(QIODevice::WriteOnly) || file.write(array) == -1) {
		file.close();
		emit(error("Unable to Write to File: " + filename));
		return;
	}

	file.close();

	clear();
}

void MainWindow::slotSaveAs()
{
	QString name = QFileDialog::getSaveFileName(this, "Save File As...", QString(), "LBlockML files (*.lml)");

	if (name.isEmpty())
		return;

	filename = name;

	if (! filename.endsWith(".lml"))
		filename = filename + ".lml";

	slotSave();
}

void MainWindow::slotAbout()
{
	QMessageBox::about(this, "About LBlock", 
"LBlock is an 8th Semester Project by <br>"
"<ul>"
"<li>Tejas Dinkar</li>"
"<li>Thejaswi K</li>"
"<li>Sourav Sarkar</li>"
"</ul>");

}

void MainWindow::slotAboutQt()
{
	QMessageBox::aboutQt(this, "About Qt");
}

void MainWindow::slotMakeDirty()
{
	if (! dirty)
		setWindowTitle(QString("LBlock Building Designer - ") + filename + "*");

	dirty = true;
}

void MainWindow::slotMakeClean()
{
	if (dirty) {
		if (! filename.isEmpty())
			setWindowTitle(QString("LBlock Building Designer - ") + filename);
		else
			setWindowTitle("LBlock Building Designer");
	}

	dirty = false;
}

void MainWindow::slotErrorHandler(QString message)
{
	QMessageBox::critical(this, "Error", message);
}

bool MainWindow::okToClose()
{
	if (! dirty)
		return true;

	QMessageBox msgBox;
	msgBox.setIcon(QMessageBox::Warning);
	msgBox.setText("The document has been modified.");
	msgBox.setInformativeText("Do you want to save your changes?");
	msgBox.setStandardButtons(QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel);
	msgBox.setDefaultButton(QMessageBox::Save);
	int ret = msgBox.exec();

	// Don't Close if Cancel
	if (ret == QMessageBox::Cancel)
		return false;

	if (ret == QMessageBox::Save)
		slotSave();

	return true;
}

void MainWindow::closeEvent(QCloseEvent *event)
{
	if (okToClose())
		event->accept();
	else
		event->ignore();
}

void MainWindow::slotProperties()
{
	PropertiesDialog *dialog = new PropertiesDialog(&doc);
	connect(dialog, SIGNAL(accepted()), this, SLOT(clear()));
	connect(dialog, SIGNAL(finished(int)), dialog, SLOT(deleteLater()));
	dialog->show();
}

void MainWindow::slotExecute()
{
	GLBox *widget = new GLBox(&doc);
	widget->setWindowState(Qt::WindowFullScreen);
	connect(widget, SIGNAL(terminated()), widget, SLOT(deleteLater()));
	widget->show();
}

inline QGraphicsRectItem *createWall(const QDomElement &wall)
{
	QGraphicsRectItem *item = new QGraphicsRectItem(0, 0, wall.attribute("length").toFloat() * PIXELS_PER_FOOT, wall.attribute("thickness", "0.5").toFloat() * PIXELS_PER_FOOT);
	item->setBrush(QBrush(Qt::black, Qt::SolidPattern));
	item->setPos(wall.attribute("x").toFloat() * PIXELS_PER_FOOT, wall.attribute("z").toFloat() * PIXELS_PER_FOOT);
	item->rotate(wall.attribute("rotation").toFloat());
	return item;
}

#include <QDebug>
void MainWindow::slotShowFloor(int n)
{
	clear();
	current_floor = n;

	QDomNode floor;

	for (floor = doc.elementsByTagName("floors").item(0).toElement().firstChild(); !floor.isNull(); floor = floor.nextSibling())
		if (floor.toElement().attribute("id") == QString::number(n)) 
			for (QDomNode item = floor.toElement().elementsByTagName("item").item(0); !item.isNull(); item = item.nextSibling())

				if (item.toElement().attribute("type") == "wall") {
					QGraphicsItem *gitem = createWall(item.toElement());
					itemsList<<gitem;
					scene->addItem(gitem);
				}
}
