#ifndef TEXTURESWINDOW_H
#define TEXTURESWINDOW_H

#include <QDialog>
#include <QStandardItemModel>
#include <QString>

#include "textureslist.h"

namespace Ui {
	class TexturesWindow;
}

class TexturesWindow : public QDialog {
	Q_OBJECT

	Ui::TexturesWindow *ui;

	TexturesList model;

	QDomDocument *doc;

    public:
	TexturesWindow(QDomDocument *doc, QWidget *parent = NULL);

	~TexturesWindow();

	void refresh();

    public slots:
	
	void slotEditTexture(QString);
};

#endif
