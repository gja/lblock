#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "ui_mainwindow.h"
#include <QMainWindow>

class MainWindow : public QMainWindow {
	Q_OBJECT
	Ui::MainWindow ui;

    public:
	MainWindow (QWidget *parent = NULL);
};

#endif
