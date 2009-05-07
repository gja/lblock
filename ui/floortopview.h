#ifndef FLOORTOPVIEW_H
#define FLOORTOPVIEW_H

#include <QGraphicsView>
#include <QPoint>
#include <QHash>

class QMouseEvent;
class QEvent;

class FloorTopView : public QGraphicsView {
	Q_OBJECT

	bool creatingItem;
	QGraphicsRectItem *currentItem;
	QPoint startingPos;

	void createItem(const QPoint &pos);
	void deleteItem();

    public:
	FloorTopView(QWidget *parent = NULL);

	virtual void mousePressEvent(QMouseEvent *event);
	virtual void mouseMoveEvent(QMouseEvent *event);
	virtual void mouseReleaseEvent(QMouseEvent *event);
	virtual void leaveEvent(QEvent *event);

	QString getCurrentItemType();

    signals:

	// This signal is emitted when a new item should be created
	void newItem(QHash<QString, QString>);
};

#endif
