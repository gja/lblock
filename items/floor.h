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

	/// This contains the lower texture of the floor.
	Texture lowerTexture;

	/// This contains the upper texture of the floor.
	Texture upperTexture;

	/// The thickness of the floor.
	float thickness;

	/// The length of the floor
	float length;
	
	/// The width of the floor
	float width;

    public:

	/**
	 * This is the constructor. It creates the floor for a given set of parameters
	 * \param x The x Coordinate
	 * \param y The y Coordinate
	 * \param z The z Coordinate
	 * \param r The rotation
	 * \param ut It contains the upper texture
	 * \param lt It contains the lower texture
	 * \param t The thickness of the floor, default value is 0.1
	 */
	Floor(float x, float y, float z, float r, float l, float w, const Texture &ut = Texture(0xFFFFFF), const Texture &lt = Texture(0xFFFFFF), float t = 0.1f)
		: Item(x, y, z, r), upperTexture(ut), lowerTexture(lt), thickness(t), length(l), width(w)
	{
	}

	/// This generates the call list to draw the floor
	virtual void generateList();
};

#endif
