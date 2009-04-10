#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "textureswindow.h"

#include <QDomDocument>
#include <QMainWindow>
#include <QActionGroup>

namespace Ui {
	class MainWindow;
}

class QGraphicsScene;

class MainWindow : public QMainWindow {
	Q_OBJECT

	Ui::MainWindow *ui;

	TexturesWindow texturesWindow;

	QActionGroup group;

	/// This is true if the file has been modified
	bool dirty;

	/// This Stores the Current filename
	QString filename;

	/// This stores the document currently being read
	QDomDocument doc;

	/// This stores the scene to draw everything
	QGraphicsScene *scene;

	/// This stores the current floor
	int current_floor;

    public:
	MainWindow (QWidget *parent = NULL);

	~MainWindow();

	/**
	 * This checks if there is unsaved changes in the file.
	 * This asks the user to save, and returns afterwards
	 * \return true if it is safe to close
	 */
	bool okToClose();

	void closeEvent(QCloseEvent *event);

    signals:
	void error(QString);

	void enableButtons(bool);

    public slots:

	/// This function clears everything (except filename)
	void clear();

	void slotNew();

	void slotOpen();

	void slotSave();

	void slotSaveAs();

	void slotAbout();

	void slotAboutQt();

	void slotMakeDirty();

	void slotMakeClean();

	void slotErrorHandler(QString);

	void slotExecute();

	void slotProperties();

	void slotShowFloor(int);
};

#endif
