#ifndef FLOOR_H
#define FLOOR_H

#include "item.h"
#include "texture.h"

#include <QList>
#include <QPointF>

class Floor : public Item {
	QList <QPointF> points;
	Texture texture;

    public:
	
	// This function is used to add points to the floor structure. Add points in a clockwise fashion
	// 0, 0 is automatically added for you
	inline void addPoint(float x, float z)
	{
		addPoint(QPointF(x, z));
	}

	inline void addPoint(const QPointF &point)
	{
		points<<point;
	}

	Floor(float x, float y, float z, float r, const Texture &t = Texture(0xFFFFFF)) : Item(x, y, z, r)
	{
		addPoint(0.0f, 0.0f);
		texture = t;
	}

	virtual void generateList();
};

#endif
