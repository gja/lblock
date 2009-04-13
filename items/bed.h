#ifndef BED_H
#define BED_H

#include "item.h"
#include "texture.h"

#include <QList>
#include <QMatrix>

/**
 * This class contains all the functions that can be used to build a table.
 * It contains all the attributes neccessary for building a table.
 */

class Bed : public Item
{
    protected:

	/// This is the length of the table.
	GLfloat length;

	/// This is the width of the table.
	GLfloat width;

	/// This is the height of the table.
	GLfloat height;

	/// This represents the texture of the table.
	Texture texture;

	/// This stores the matrix for collision detection
	QMatrix collisionMatrix;

    public:
	/**
	 * This is the constructor, it can be used to build the table.
	 * \param x It contains the x coordinate of the table
	 * \param y It contains the y coordinate of the table
	 * \param z It contains the z coordinate of the table
	 * \param rotation It represents the angle of rotation for the table
	 * \param length It contains the length of the table
	 * \param height It contains the height of the table, default value is 10
	 * \param texture It represents the inner texture of the tables
	 */
	Bed(float x, float y, float z, float rotation, float length, float width, float height = 5.0f, const Texture &texture = Texture());

	/// The destructor.
	~Bed();

	/**
	 * This function is used to set the height of the table.
	 * \param x Height of the table.
	 */
	inline void setHeight(float x)  { height=x; }

	/// This function returns the height of the table.
	inline float getHeight()  { return height; }

	/**
	 * This function is used to set the length of the table.
	 * \param x Length of the table
	 */
	inline void setLength(float x)  { length=x; }

	/// This function is used to return the length of the table.
	inline float getLength() { return length; }

	/**
	 * This function is used to set the width of the table.
	 * \param x Width of the table
	 */
	inline void setWidth(float x)  { width=x; }

	/// This function is used to return the width of the table.
	inline float getWidth() { return width; }

	/**
	 * This function is used to set the inner texture of the table.
	 * \param i represents the inner texture of the table that is to be set
	 */
	inline void setTexture(const Texture &i) { texture = i; };

	/// This function returns the value of the inner texture.
	inline const Texture &getTexture() { return texture; }

	/// This function generates the CallList. This CallList is stored in \ref Item::object
	virtual void generateList();

	/** This method checks if a point collides with this object
	 * \param x The X position of the point
	 * \param y The Y position of the point
	 * \param z The Z position of the point
	 * \return true if there is a collision, false otherwise
	 */
	virtual bool isCollision(float x, float y, float z);

    private:
};

#endif

