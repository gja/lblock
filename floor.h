#ifndef FLOOR_H
#define FLOOR_H

#include "item.h"
#include "texture.h"

#include <QList>
#include <QPointF>

/**
 * This class is used to add the floor to a model.
 * It contains functions for adding floor to the model.
 * This class inherits the Item class.
 */
class Floor : public Item {

	/// A set of points which defines the area for which the floor should be added.
	QList <QPointF> points;

	/// This contains the lower texture of the floor.
	Texture lowerTexture;

	/// This contains the upper texture of the floor.
	Texture upperTexture;

	/// The thickness of the floor.
	float thickness;

    public:
	
	/**
	 * This function is used to add points to the floor structure. 
	 * Add points in a clockwise fashion. (0,0) will be added for you.
	 * \param x The x coordinate
	 * \param z The z coordinate
	 */
	inline void addPoint(float x, float z)
	{
		addPoint(QPointF(x, z));
	}

	/**
	 * This function is used to add the point into a list of points
	 * \param point Contains the point (x,z).
	 */
	inline void addPoint(const QPointF &point)
	{
		points<<point;
	}

	/**
	 * This is the constructor. It creates the floor for a given set of parameters
	 * \param x The x Coordinate
	 * \param y The y Coordinate
	 * \param z The z Coordinate
	 * \param r The rotation
	 * \param ut It contains the upper texture
	 * \param lt It contains the lower texture
	 * \t The thickness, default value is 0.1
	 */
	Floor(float x, float y, float z, float r, const Texture &ut = Texture(0xFFFFFF), const Texture &lt = Texture(0xFFFFFF), float t = 0.1f) 
		: Item(x, y, z, r), upperTexture(ut), lowerTexture(lt), thickness(t)
	{
		addPoint(0.0f, 0.0f);
	}

	/// This generates the call list to draw the floor
	virtual void generateList();
};

#endif
