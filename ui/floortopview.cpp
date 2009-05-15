#include "floortopview.h"
#include "constants.h"
#include "lblockgraphicsitem.h"
#include "addwindow.h"

#include <QMouseEvent>
#include <QGraphicsLineItem>
#include <math.h>
#include <QMenu>
#include <QIcon>

FloorTopView::FloorTopView(QWidget *parent) : QGraphicsView(parent), creatingItem(false), currentItem(NULL), currentItemType("none")
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
	if (event->button() == Qt::RightButton) {
		LBlockGraphicsItem *item = dynamic_cast<LBlockGraphicsItem *>(itemAt(event->pos()));
		if (item) {
			if (item->getName().startsWith("wall")) {
				QMenu menu;
				menu.addAction(QIcon(":/icons/icons/list-add.png"), "Add Window", this, SLOT(addWindow()));
				menu.addAction(QIcon(":/icons/icons/list-add.png"), "Add Door", this, SLOT(addDoor()));
				menu.exec(mapToGlobal(event->pos()));
			}

			emit itemSelected(item->getName());
		}

		return;
	}

	if (getCurrentItemType() != "none")
		createItem(event->pos());
	else {
		LBlockGraphicsItem *item = dynamic_cast<LBlockGraphicsItem *>(itemAt(event->pos()));
		if (item)
			emit itemSelected(item->getName());
	}
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

		if (getCurrentItemType() == "wall") {

			float rot = atan((float) rel.y() / float(rel.x())) * 180. / M_PI;
			if (rel.x() < 0)
				rot += 180.;
			if (rot < 0)
				rot += 360;
			properties["rotation"] = QString::number(rot);
			qreal length = sqrt(pow(rel.x(), 2) + pow(rel.y(), 2));
			properties["length"] = QString::number(length / PIXELS_PER_FOOT);
			properties["height"] = "10";
			properties["thickness"] = "0.5";
			properties["innerTexture"] = "white";
			properties["outerTexture"] = "white";
		} else if (getCurrentItemType() == "table" || getCurrentItemType() == "chair" || getCurrentItemType() == "bed" || getCurrentItemType() == "sofa" || getCurrentItemType() == "tv") {
			properties["rotation"] = "0.0";
			properties["length"] = QString::number((float) rel.y() / PIXELS_PER_FOOT);
			properties["width"] = QString::number((float) rel.x() / PIXELS_PER_FOOT);
			properties["height"] = "4.0";
			properties["texture"] = "white";
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

	if (getCurrentItemType() == "wall") {
		qreal length = sqrt(pow(rel.x(), 2) + pow(rel.y(), 2));

		float rot = atan((float) rel.y() / float(rel.x())) * 180. / M_PI;
		if (rel.x() < 0)
			rot += 180.;
		if (rot < 0)
			rot += 360;

		currentItem->setRect(0, 0, length, PIXELS_PER_FOOT / 2);
		currentItem->setTransform(QTransform().translate(startingPos.x(), startingPos.y()).rotate(rot));
	} else if (getCurrentItemType() == "table" || getCurrentItemType() == "chair" || getCurrentItemType() == "bed" || getCurrentItemType() == "sofa" || getCurrentItemType() == "tv") {
		currentItem->setRect(startingPos.x(), startingPos.y(), rel.x(), rel.y());
	}
}

void FloorTopView::setCurrentItemType(const QString &string)
{
	currentItemType = string;
}

void FloorTopView::addWindow()
{
	AddWindow window;
	window.exec();
}

void FloorTopView::addDoor()
{
	qDebug("Door");
}
