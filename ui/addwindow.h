#ifndef ADDWINDOW_H
#define ADDWINDOW_H

#include <QDialog>

#include "ui_addwindow.h"

class AddWindow : public QDialog {
	Q_OBJECT

    public:
	Ui::AddWindow ui;

	AddWindow(QWidget *parent = NULL);
};

class AddDoor : public AddWindow {

    public:
	AddDoor(QWidget *parent = NULL);
};

#endif
