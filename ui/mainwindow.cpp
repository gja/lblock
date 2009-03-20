#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "glbox.h"

#include <QCloseEvent>
#include <QFileDialog>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), texturesWindow(&doc, this), doc("LBlockML"), dirty(false)
{
	ui = new Ui::MainWindow;

	ui->setupUi(this);
	texturesWindow.show();

	connect(ui->actionTextures, SIGNAL(toggled(bool)), &texturesWindow, SLOT(setVisible(bool)));
	connect(&texturesWindow, SIGNAL(rejected()), ui->actionTextures, SLOT(toggle()));
	
	connect(this, SIGNAL(error(QString)), this, SLOT(slotErrorHandler(QString)));

	slotNew();
}

MainWindow::~MainWindow()
{
	delete ui;
}

void MainWindow::clear()
{
	texturesWindow.refresh();
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
" <textures/>\n"
" <floors/>\n"
"</lblock>\n"));
	clear();
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

	dirty = 1;
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

#include <QDebug>
void MainWindow::slotErrorHandler(QString message)
{
	qDebug()<<message;
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

void MainWindow::slotExecute()
{
	GLBox *widget = new GLBox(&doc);
	widget->setWindowState(Qt::WindowFullScreen);
	widget->show();
}
