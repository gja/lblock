#ifndef FLOORTOPVIEW_
#define FLOORTOPVIEW_H

#include <QGraphicsView>
#include <QPoint>
#include <QHash>
#include <QString>

#include "lblockxmlengine.h"

class QMouseEvent;
class QEvent;

/**
 * This widget contains the top view of the models.
 * It contains functions for the mouse events like the select, drag and other mouse related events.
 */
class FloorTopView : public QGraphicsView {
	Q_OBJECT
	
	/// Its set to \true if we are currently creating an item.
	bool creatingItem;

	/// This is the actual item being created.
	QGraphicsRectItem *currentItem;

	/// This is the name of the Item currently being modified
	QString currentItemName;

	/// It holds the starting position of the item being created.
	QPoint startingPos;
	
	/// It is a function to create an item.
	void createItem(const QPoint &pos);

	/// Its a function for deleting the item.
	void deleteItem();
	
	/// It contains the type of item being created.
	QString currentItemType;

	LBlockXmlEngine *doc;

    public:
    	/// This widget constructs the the top view.
	FloorTopView(QWidget *parent = NULL);
	
	/// This creates a slot for the key press event.
	virtual void mousePressEvent(QMouseEvent *event);
	/// This function takes care of the mouse movements.
	virtual void mouseMoveEvent(QMouseEvent *event);
	/// This function is called when the mouse button is released.
	virtual void mouseReleaseEvent(QMouseEvent *event);
	/// This function is called when the mouse moves out of boundary.
	virtual void leaveEvent(QEvent *event);
	
	/// This function returns the type of the item being selected
	const inline QString &getCurrentItemType()
	{
		return currentItemType;
	}

	inline void setDoc(LBlockXmlEngine *d) {
		doc = d;
	}

    signals:

	/// This signal is emitted when a new item should be created
	void newItem(QHash<QString, QString>);
	
	/// This function is called when the item is selected
	void itemSelected(QString);

    public slots:
    	/// This function returns the ype of item being selected
	void setCurrentItemType(const QString &string);
	
	/// This function is called when we need to add a door
	void addDoor();
	
	/// This function is called when we need to add a window
	void addWindow();

	void deleteItemFromXML();
};

#endif
