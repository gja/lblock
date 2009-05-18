#ifndef ADDWINDOW_H
#define ADDWINDOW_H

#include <QDialog>

#include "ui_addwindow.h"

namespace Ui {
	class AddWindow;
}

/**
 * This class shows the dialog to take in the attributes of the window.
 * It pops up a dialog for taking in the attributes of the window like the 
 * length, height and position
 */
class AddWindow : public QDialog {
	Q_OBJECT
	
	/// This holds all the UI related objects.

    public:
	Ui::AddWindow ui;

	AddWindow(QWidget *parent = NULL);
};

class AddDoor : public AddWindow {

    public:
	AddDoor(QWidget *parent = NULL);
};

#endif
