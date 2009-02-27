#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), texturesWindow(this)
{
	ui = new Ui::MainWindow;

	ui->setupUi(this);
	texturesWindow.show();

	connect(ui->actionTextures, SIGNAL(toggled(bool)), &texturesWindow, SLOT(setVisible(bool)));
	connect(&texturesWindow, SIGNAL(rejected()), ui->actionTextures, SLOT(toggle()));
}

MainWindow::~MainWindow()
{
	delete ui;
}

void MainWindow::clear()
{
	delete ui;

	MainWindow(parent);
}

void MainWindow::slotNew()
{
	filename.clear();
	clear();
}

void MainWindow::slotOpen()
{
	qDebug()<<"Hello";
}

void MainWindow::slotSave()
{
	qDebug()<<"Hello";
}

void MainWindow::slotSaveAs()
{
	qDebug()<<"Hello";
}
