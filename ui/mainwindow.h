#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "textureswindow.h"

#include <QMainWindow>

namespace Ui {
	class MainWindow;
}

class MainWindow : public QMainWindow {
	Q_OBJECT

	Ui::MainWindow *ui;

	TexturesWindow texturesWindow;

    public:
	MainWindow (QWidget *parent = NULL);

	~MainWindow();
};

#endif
