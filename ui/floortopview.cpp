#include "floortopview.h"
#include "constants.h"

#include <QMouseEvent>
#include <QGraphicsLineItem>

FloorTopView::FloorTopView(QWidget *parent) : QGraphicsView(parent), creatingItem(false), currentItem(NULL)
{
}

void FloorTopView::createItem(const QPoint &pos)
{
	creatingItem = true;
	startingPos = pos;

	if (! currentItem) {
		currentItem = new QGraphicsLineItem;
		QPen pen = currentItem->pen();
		pen.setWidth(0.5 * PIXELS_PER_FOOT);
		currentItem->setPen(pen);

		scene()->addItem(currentItem);
	}
}

void FloorTopView::deleteItem()
{
	creatingItem = false;

	if (currentItem) {
		scene()->removeItem(currentItem);
		delete currentItem;
		currentItem = NULL;
	}
}

void FloorTopView::mousePressEvent(QMouseEvent *event)
{
	createItem(event->pos());
}

void FloorTopView::leaveEvent(QEvent *event)
{
	deleteItem();
}

void FloorTopView::mouseReleaseEvent(QMouseEvent *event)
{
	deleteItem();
}

void FloorTopView::mouseMoveEvent(QMouseEvent *event)
{
	if (! creatingItem)
		return;

	currentItem->setLine(QLine(startingPos, event->pos()));
}
