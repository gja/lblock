#include "floortopview.h"
#include "constants.h"

#include <QMouseEvent>
#include <QGraphicsLineItem>
#include <math.h>

FloorTopView::FloorTopView(QWidget *parent) : QGraphicsView(parent), creatingItem(false), currentItem(NULL)
{
}

void FloorTopView::createItem(const QPoint &pos)
{
	creatingItem = true;
	startingPos = pos;

	if (! currentItem) {
		currentItem = new QGraphicsRectItem;
		currentItem->setBrush(Qt::SolidPattern);
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
	if (creatingItem)
		deleteItem();
}

void FloorTopView::mouseReleaseEvent(QMouseEvent *event)
{
	if (creatingItem) {
		QHash <QString, QString> properties;
		properties["type"] = getCurrentItemType();
		properties["name"] = getCurrentItemType() + QString::number(qrand());
		properties["x"] = QString::number((float) startingPos.x() / PIXELS_PER_FOOT);
		properties["y"] = "0";
		properties["z"] = QString::number((float) startingPos.y() / PIXELS_PER_FOOT);

		QPoint rel = event->pos() - startingPos;
		float rot = atan((float) rel.y() / float(rel.x())) * 180. / M_PI;
		if (rel.x() < 0)
			rot += 180.;
		if (rot < 0)
			rot += 360;
		properties["rotation"] = QString::number(rot);

		if (getCurrentItemType() == "wall") {
			qreal length = sqrt(pow(rel.x(), 2) + pow(rel.y(), 2));
			properties["length"] = QString::number(length / PIXELS_PER_FOOT);
			properties["height"] = "10";
			properties["thickness"] = "0.5";
			properties["innerTexture"] = "white";
			properties["outerTexture"] = "white";
		}

		emit newItem(properties);
		deleteItem();
	}
}

void FloorTopView::mouseMoveEvent(QMouseEvent *event)
{
	if (! creatingItem)
		return;

	QPoint rel = event->pos() - startingPos;
	qreal length = sqrt(pow(rel.x(), 2) + pow(rel.y(), 2));

	float rot = atan((float) rel.y() / float(rel.x())) * 180. / M_PI;
	if (rel.x() < 0)
		rot += 180.;
	if (rot < 0)
		rot += 360;

	currentItem->setRect(0, 0, length, PIXELS_PER_FOOT / 2);
	currentItem->setTransform(QTransform().translate(startingPos.x(), startingPos.y()).rotate(rot));
}

QString FloorTopView::getCurrentItemType()
{
	return "wall";
}
