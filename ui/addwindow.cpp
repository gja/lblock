#include "addwindow.h"

AddWindow::AddWindow(QWidget *parent) : QDialog(parent)
{
	ui.setupUi(this);
}

AddDoor::AddDoor(QWidget *parent) : AddWindow(parent)
{
	ui.lowerHeight->setValue(0.0);
	ui.lowerHeight->hide();
	ui.label_4->hide();
}
