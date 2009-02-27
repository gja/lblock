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

	/// This Stores the Current filename
	QString filename;

	/// This function clears everything (except filename)
	void clear();

    public:
	MainWindow (QWidget *parent = NULL);

	~MainWindow();

    public slots:

	void slotNew();

	void slotOpen();

	void slotSave();

	void slotSaveAs();
};

#endif
