#ifndef ITEMPROPERTIESVIEW_H
#define ITEMPROPERTIESVIEW_H

#include <QListView>
/**
 * This class contains the properties of the item in the view mode.
 */
class ItemPropertiesView : public QListView {

	Q_OBJECT

    public:
    	/// This function displays the item property module
	ItemPropertiesView(QWidget *parent = NULL);
	/// This function is called when the mouse is double clicked
	void mouseDoubleClickEvent(QMouseEvent *event);

    signals:
    	/// This function is called when the attribute is modifed
	void modifyAttribute(QString);
};

#endif
