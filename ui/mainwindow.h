#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "textureswindow.h"
#include "lblockxmlengine.h"
#include "itemproperties.h"

#include <QMainWindow>
#include <QActionGroup>
#include <QHash>
#include <QString>

namespace Ui {
	class MainWindow;
}

class QGraphicsScene;
class QGraphicsItem;
/**
 * This class contain functions for all the actions performed on the main screen
 */

class MainWindow : public QMainWindow {
	Q_OBJECT
	/// This hold all the ui related objects
	Ui::MainWindow *ui;
	
	/// This contains the textures used for the window
	TexturesWindow texturesWindow;
	
	/// This contains the properties of the item
	ItemPropertiesDialog itemProperties;
	
	/// It contains the action for the each button pressed
	QActionGroup group;

	/// This is true if the file has been modified
	bool dirty;

	/// This Stores the Current filename
	QString filename;

	/// This stores the document currently being read
	LBlockXmlEngine doc;

	/// This stores the scene to draw everything
	QGraphicsScene *scene;

	/// This stores all the QGraphicsItems that we draw
	QList <QGraphicsItem *> itemsList;

	/// This stores the current floor
	int current_floor;

	/// This stores the current Item
	QString currentItem;

    public:
	MainWindow (QWidget *parent = NULL);

	~MainWindow();

	/**
	 * This checks if there is unsaved changes in the file.
	 * This asks the user to save, and returns afterwards
	 * \return true if it is safe to close
	 */
	bool okToClose();
	
	/// This function is called when the clse action is performed
	void closeEvent(QCloseEvent *event);

    signals:
    	/// This function signals an error
	void error(QString);

	/// This function enables all the buttons on the main window
	void enableButtons(bool);
	
	/// This function is for selecting the particular item specified
	void itemSelected(LBlockValues);
	
	/// This function signals that the selected item has been changed
	void currentItemChanged(QString);

    public slots:

	/// This function clears everything (except filename)
	void clear();
	
	/// This function creates a new file
	void slotNew();

	/// This function opens the file
	void slotOpen();
	
	/// This function saves the selected file
	void slotSave();
	
	/// This function is for the save as operation on the file
	void slotSaveAs();
	
	/// This function is for the about operation
	void slotAbout();

	/// This function is for the information related to Qt
	void slotAboutQt();
	
	/// This function ensures that file has to be saved once a change has been done
	void slotMakeDirty();

	/// This function indicates that the file has been saved after recent changes
	void slotMakeClean();
	
	/// This function is called when a error occurs
	void slotErrorHandler(QString);

	/// This function is for execute operation
	void slotExecute();
	
	/// This function shows the properties of the file
	void slotProperties();
	
	/// This function shows the floor
	void slotShowFloor(int floor, bool force = false);
	
	/// This function opens the new item selected
	void slotNewItem(const QHash<QString, QString> &hash);
	
	/// This function is called when a item is selected
	void slotItemSelected(const QString &hash);
	
	/// This function is for performing refresh
	void slotRefresh();
	
	/// This function is to identify the currently changed items
	void currentChanged(bool toggled);
};

#endif
