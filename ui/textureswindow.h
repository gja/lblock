#ifndef TEXTURESWINDOW_H
#define TEXTURESWINDOW_H

#include <QDialog>
#include <QStandardItemModel>

namespace Ui {
	class TexturesWindow;
}

class TexturesWindow : public QDialog {
	Q_OBJECT

	Ui::TexturesWindow *ui;

	QStandardItemModel model;

    public:
	TexturesWindow(QWidget *parent = NULL);

	~TexturesWindow();
};

#endif
