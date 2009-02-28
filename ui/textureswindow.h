#ifndef TEXTURESWINDOW_H
#define TEXTURESWINDOW_H

#include <QDialog>
#include <QStandardItemModel>

#include "textureslist.h"

namespace Ui {
	class TexturesWindow;
}

class TexturesWindow : public QDialog {
	Q_OBJECT

	Ui::TexturesWindow *ui;

	TexturesList model;

    public:
	TexturesWindow(QDomDocument *doc, QWidget *parent = NULL);

	~TexturesWindow();

	void refresh();
};

#endif
