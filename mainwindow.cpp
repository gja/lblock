#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), texturesWindow(this)
{
	ui.setupUi(this);
	texturesWindow.show();

	connect(ui.actionTextures, SIGNAL(toggled(bool)), &texturesWindow, SLOT(setVisible(bool)));
	connect(&texturesWindow, SIGNAL(rejected()), ui.actionTextures, SLOT(toggle()));
}
