#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "glbox.h"
#include "properties.h"
#include "constants.h"
#include "lblockgraphicsitem.h"

#include <QCloseEvent>
#include <QFileDialog>
#include <QMessageBox>
#include <QGraphicsScene>
#include <QGraphicsItem>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), texturesWindow(&doc, this), doc("LBlockML"), dirty(false), group(NULL), itemProperties(this)
{
	ui = new Ui::MainWindow;

	ui->setupUi(this);
	texturesWindow.show();

	itemProperties.show();

	scene = new QGraphicsScene;
	ui->graphicsView->setScene(scene);

	group.addAction(ui->actionBed);
	group.addAction(ui->actionChair);
	group.addAction(ui->actionFloor);
	group.addAction(ui->actionSofa);
	group.addAction(ui->actionStairs);
	group.addAction(ui->actionTable);
	group.addAction(ui->actionTV);
	group.addAction(ui->actionWall);

	connect(ui->actionTextures, SIGNAL(toggled(bool)), &texturesWindow, SLOT(setVisible(bool)));
	connect(ui->actionItemProperties, SIGNAL(toggled(bool)), &itemProperties, SLOT(setVisible(bool)));
	connect(&texturesWindow, SIGNAL(rejected()), ui->actionTextures, SLOT(toggle()));
	
	connect(this, SIGNAL(error(QString)), this, SLOT(slotErrorHandler(QString)));

	connect(ui->graphicsView, SIGNAL(newItem(QHash<QString, QString>)), this, SLOT(slotNewItem(QHash<QString, QString>)));
	connect(ui->graphicsView, SIGNAL(itemSelected(QString)), this, SLOT(slotItemSelected(QString)));

	connect(this, SIGNAL(itemSelected(QDomElement)), &itemProperties, SLOT(setItem(QDomElement)));

	connect(&itemProperties, SIGNAL(dirty()), this, SLOT(slotMakeDirty()));
	connect(&itemProperties, SIGNAL(dirty()), this, SLOT(slotRefresh()));

	connect(ui->actionBed, SIGNAL(toggled(bool)), this, SLOT(currentChanged(bool)));
	connect(ui->actionChair, SIGNAL(toggled(bool)), this, SLOT(currentChanged(bool)));
	connect(ui->actionFloor, SIGNAL(toggled(bool)), this, SLOT(currentChanged(bool)));
	connect(ui->actionSofa, SIGNAL(toggled(bool)), this, SLOT(currentChanged(bool)));
	connect(ui->actionStairs, SIGNAL(toggled(bool)), this, SLOT(currentChanged(bool)));
	connect(ui->actionTable, SIGNAL(toggled(bool)), this, SLOT(currentChanged(bool)));
	connect(ui->actionTV, SIGNAL(toggled(bool)), this, SLOT(currentChanged(bool)));
	connect(ui->actionWall, SIGNAL(toggled(bool)), this, SLOT(currentChanged(bool)));

	connect(this, SIGNAL(currentItemChanged(QString)), ui->graphicsView, SLOT(setCurrentItemType(QString)));

	slotNew();
}

MainWindow::~MainWindow()
{
	delete ui;
	delete scene;
}

inline QDomNode getCurrentFloor(const QDomDocument &doc, int n)
{
	QDomNode floor;
	for (floor = doc.elementsByTagName("floors").item(0).toElement().firstChild(); !floor.isNull(); floor = floor.nextSibling())
		if (floor.toElement().attribute("id") == QString::number(n))
			return floor;
}

void MainWindow::clear()
{
	texturesWindow.refresh();

	QDomElement elem = doc.documentElement().toElement().elementsByTagName("properties").item(0).toElement();

	int grid = elem.attribute("grid", "10").toInt();
	int length = elem.attribute("length", "60").toInt();
	int width = elem.attribute("width", "40").toInt();

	if (! itemsList.isEmpty()) {
		qDeleteAll(itemsList);
		itemsList.clear();
	}

	scene->clear();
	scene->setSceneRect(0, 0, length * PIXELS_PER_FOOT, width * PIXELS_PER_FOOT);

	ui->floorNumber->setRange(elem.attribute("lowest", "0").toInt(), elem.attribute("highest", "0").toInt());
	ui->floorNumber->setValue(current_floor);
	ui->floorNumber->update();

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
}

void MainWindow::slotNew()
{
	if (! okToClose())
		return;

	filename.clear();
	doc.setContent(QString(
"<!DOCTYPE LBlockML>\n"
"<lblock>\n"
" <properties width=\"40\" lowest=\"0\" grid=\"10\" length=\"60\" highest=\"0\" />"
" <textures />\n"
" <floors>\n"
"  <floor id=\"0\" />\n"
" </floors>\n"
"</lblock>\n"
));
	current_floor = 0;
	slotRefresh();
	slotMakeClean();
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
	slotMakeClean();

	QDomElement elem = doc.documentElement().elementsByTagName("properties").item(0).toElement();

	current_floor = elem.attribute("lowest").toInt();
	slotShowFloor(current_floor, true);
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

	slotMakeClean();
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

inline LBlockGraphicsItem *createWall(const QDomElement &wall)
{
	LBlockGraphicsItem *item = new LBlockGraphicsItem(0, 0, wall.attribute("length").toFloat() * PIXELS_PER_FOOT, wall.attribute("thickness", "0.5").toFloat() * PIXELS_PER_FOOT, wall.attribute("name"));
	item->setBrush(QBrush(Qt::black, Qt::SolidPattern));
	item->setPos(wall.attribute("x").toFloat() * PIXELS_PER_FOOT, wall.attribute("z").toFloat() * PIXELS_PER_FOOT);
	item->rotate(wall.attribute("rotation").toFloat());
	return item;
}

inline LBlockGraphicsItem *createGenericItem(const QDomElement &item)
{
	LBlockGraphicsItem *gitem = new LBlockGraphicsItem(0, 0, item.attribute("length").toFloat() * PIXELS_PER_FOOT, item.attribute("width", "0.5").toFloat() * PIXELS_PER_FOOT, item.attribute("name"));
	gitem->setBrush(QBrush(Qt::black, Qt::SolidPattern));
	gitem->setPos(item.attribute("x").toFloat() * PIXELS_PER_FOOT, item.attribute("z").toFloat() * PIXELS_PER_FOOT);
	gitem->rotate(item.attribute("rotation").toFloat());
	return gitem;
}

void MainWindow::slotShowFloor(int n, bool force)
{
	if (current_floor == n && !force)
		return;

	current_floor = n;
	clear();

	QDomNode floor;

	for (floor = doc.elementsByTagName("floors").item(0).toElement().firstChild(); !floor.isNull(); floor = floor.nextSibling())
		if (floor.toElement().attribute("id") == QString::number(n)) 
			for (QDomNode item = floor.toElement().elementsByTagName("item").item(0); !item.isNull(); item = item.nextSibling()) {

				if (item.toElement().attribute("type") == "wall") {
					QGraphicsItem *gitem = createWall(item.toElement());
					itemsList<<gitem;
					scene->addItem(gitem);
				}
				else {
					QGraphicsItem *gitem = createGenericItem(item.toElement());
					itemsList<<gitem;
					scene->addItem(gitem);
				}
			}
}

void MainWindow::slotNewItem(const QHash <QString, QString> &hash)
{
	QDomElement floor = getCurrentFloor(doc, current_floor).toElement();

	QDomElement elem = doc.createElement("item");
	QHashIterator<QString, QString> i(hash);

	while (i.hasNext()) {
		i.next();
		elem.setAttribute(i.key(), i.value());
	}

	floor.appendChild(elem);

	slotShowFloor(current_floor, true);

	slotMakeDirty();

	slotItemSelected(elem.attribute("name"));
}

void MainWindow::slotItemSelected(const QString &name)
{
	QDomElement floor = getCurrentFloor(doc, current_floor).toElement();

	QDomNode item;
	for (item = floor.elementsByTagName("item").item(0); !item.isNull(); item = item.nextSibling())
		if (item.toElement().attribute("name") == name) {
			emit itemSelected(item.toElement());
			break;
		}
}

void MainWindow::slotRefresh()
{
	slotShowFloor(current_floor, true);
}

void MainWindow::currentChanged(bool toggled)
{
	if (!toggled && ! group.checkedAction()) {
		emit currentItemChanged("none");
	} else if (toggled) {
		emit currentItemChanged(group.checkedAction()->objectName().remove(0,6).toLower());
	}
}
