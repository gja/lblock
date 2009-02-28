#ifndef TEXTURESVIEW_H
#define TEXTURESVIEW_H

#include <QListView>

class TexturesView : public QListView {

    public:
	TexturesView(QWidget *parent = NULL);

	void mouseDoubleClickEvent(QMouseEvent *event);
};

#endif
