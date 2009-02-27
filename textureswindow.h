#ifndef TEXTURESWINDOW_H
#define TEXTURESWINDOW_H

#include "ui_textureswindow.h"
#include <QDialog>

class TexturesWindow : public QDialog {
	Q_OBJECT
	Ui::TexturesWindow ui;

    public:
	TexturesWindow(QWidget *parent = NULL);
};

#endif
