#ifndef ADDWINDOW_H
#define ADDWINDOW_H

#include <QDialog>

namespace Ui {
	class AddWindow;
}

class AddWindow : public QDialog {
	Q_OBJECT

	Ui::AddWindow *ui;

    public:
	AddWindow(QWidget *parent = NULL);
};

#endif
