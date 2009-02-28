#ifndef TEXTURESVIEW_H
#define TEXTURESVIEW_H

#include <QListView>

class TexturesView : public QListView {

	Q_OBJECT

    public:
	TexturesView(QWidget *parent = NULL);

	void mouseDoubleClickEvent(QMouseEvent *event);

    signals:
	void editTexture(QString);
};

#endif
