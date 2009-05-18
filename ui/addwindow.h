#ifndef ADDWINDOW_H
#define ADDWINDOW_H

#include <QDialog>

/**
 * This class shows the dialog to take in the attributes of the window.
 * It pops up a dialog for taking in the attributes of the window like the 
 * length, height and position
 */
namespace Ui {
	class AddWindow;
}

class AddWindow : public QDialog {
	Q_OBJECT
	
	/// This holds all the UI related objects.

	Ui::AddWindow *ui;

    public:
	AddWindow(QWidget *parent = NULL);
};

#endif
