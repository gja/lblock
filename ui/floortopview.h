#ifndef FLOORTOPVIEW_H
#define FLOORTOPVIEW_H

#include <QGraphicsView>
#include <QPoint>

class QMouseEvent;
class QGraphicsItem;
class QEvent;

class FloorTopView : public QGraphicsView {
	Q_OBJECT

	bool creatingItem;
	QGraphicsLineItem *currentItem;
	QPoint startingPos;

	void createItem(const QPoint &pos);
	void deleteItem();

    public:
	FloorTopView(QWidget *parent = NULL);

	virtual void mousePressEvent(QMouseEvent *event);
	virtual void mouseMoveEvent(QMouseEvent *event);
	virtual void mouseReleaseEvent(QMouseEvent *event);
	virtual void leaveEvent(QEvent *event);
};

#endif
