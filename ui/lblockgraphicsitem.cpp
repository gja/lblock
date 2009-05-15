#include "lblockgraphicsitem.h"

void LBlockGraphicsItem::setName(const QString &basename)
{
	name = basename;
}

const QString &LBlockGraphicsItem::getName()
{
	return name;
}

LBlockGraphicsItem::LBlockGraphicsItem(float a, float b, float c, float d, const QString &name)
	: QGraphicsRectItem(a, b, c, d)
{
	setName(name);
}
