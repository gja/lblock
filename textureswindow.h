#ifndef TEXTURESWINDOW_H
#define TEXTURESWINDOW_H

#include "ui_textureswindow.h"

#include <QDialog>
#include <QStandardItemModel>

class TexturesWindow : public QDialog {
	Q_OBJECT
	Ui::TexturesWindow ui;

	QStandardItemModel model;

    public:
	TexturesWindow(QWidget *parent = NULL);
};

#endif
