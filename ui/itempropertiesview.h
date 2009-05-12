#ifndef ITEMPROPERTIESVIEW_H
#define ITEMPROPERTIESVIEW_H

#include <QListView>

class ItemPropertiesView : public QListView {

	Q_OBJECT

    public:
	ItemPropertiesView(QWidget *parent = NULL);

	void mouseDoubleClickEvent(QMouseEvent *event);

    signals:
	void modifyAttribute(QString);
};

#endif
