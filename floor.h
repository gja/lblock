#ifndef FLOOR_H
#define FLOOR_H

#include "item.h"
#include "texture.h"

#include <QList>
#include <QPointF>

class Floor : public Item {
	QList <QPointF> points;
	Texture lowerTexture;
	Texture upperTexture;
	float thickness;

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

	Floor(float x, float y, float z, float r, const Texture &lt = Texture(0xFFFFFF), const Texture &ut = Texture(0xFFFFFF), float t = 0.1f) 
		: Item(x, y, z, r), upperTexture(ut), lowerTexture(lt), thickness(t)
	{
		addPoint(0.0f, 0.0f);
	}

	virtual void generateList();
};

#endif
