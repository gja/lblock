#ifndef FLOORTOPVIEW_
#define FLOORTOPVIEW_H

#include <QGraphicsView>
#include <QPoint>
#include <QHash>
#include <QString>

#include "lblockxmlengine.h"

class QMouseEvent;
class QEvent;

class FloorTopView : public QGraphicsView {
	Q_OBJECT

	bool creatingItem;
	QGraphicsRectItem *currentItem;
	QPoint startingPos;

	/// This is the name of the Item currently being modified
	QString currentItemName;

	void createItem(const QPoint &pos);
	void deleteItem();

	QString currentItemType;

	LBlockXmlEngine *doc;

    public:
	FloorTopView(QWidget *parent = NULL);

	virtual void mousePressEvent(QMouseEvent *event);
	virtual void mouseMoveEvent(QMouseEvent *event);
	virtual void mouseReleaseEvent(QMouseEvent *event);
	virtual void leaveEvent(QEvent *event);

	const inline QString &getCurrentItemType()
	{
		return currentItemType;
	}

	inline void setDoc(LBlockXmlEngine *d) {
		doc = d;
	}

    signals:

	// This signal is emitted when a new item should be created
	void newItem(QHash<QString, QString>);

	void itemSelected(QString);

    public slots:
	void setCurrentItemType(const QString &string);

	void addDoor();

	void addWindow();

	void deleteItemFromXML();
};

#endif
