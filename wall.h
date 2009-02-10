#ifndef WALL_H
#define WALL_H

#include "item.h"
#include "texture.h"

#include <QList>
/**
 * This class contains all the functions that can be used to build a wall.
 * It contains all the attributes neccessary for building a wall. The objects of this class basically define
 * the parameters required for constructing a wall. In addition to the Wall constructor this class defines two other
 * functions addWindow (for adding a window on the wall) and addDoor (for adding a door on the wall).
 */

class Wall : public Item
{
    protected:

	/// This is the length of the wall.
	GLfloat length;

	/// This is the height of the wall.
	GLfloat height;

	/// This is the thickness of the wall.
	GLfloat thickness;

	/// This represents the inner texture of the wall.
	Texture innerTexture;

	/// This represents the outer texture of the wall.
	Texture outerTexture;

    public:
	/**
	 * This is the constructor, it can be used to build the wall.
	 * \param x It contains the x coordinate of the wall
	 * \param y It contains the y coordinate of the wall
	 * \param z It contains the z coordinate of the wall
	 * \param rotation It represents the angle of rotation for the wall
	 * \param length It contains the length of the wall
	 * \param inner It represents the inner texture of the walls
	 * \param outer It represents the outer texture of the walls
	 * \param height It contains the height of the wall, default value is 10
	 * \param thickness It contains the thickness of the wall, default value is 0.5
	 */
	Wall(float x, float y, float z, float rotation, float length, const Texture &inner = Texture(), const Texture &outer = Texture(), float height = 10.0f, float thickness = 0.5f);

	/// The destructor.
	~Wall();

	/**
	 * This function is used to set the height of the wall.
	 * \param x Height of the wall.
	 */
	inline void setHeight(float x)  { height=x; }

	/// This function returns the height of the wall.
	inline float getHeight()  { return height; }

	/**
	 * This function is used to set the thickness of the wall.
	 * \param x Thickness of the wall
	 */
	inline void setThickness(float x)  { thickness=x;  }

	/// This function is used to return the thickness of the wall.
	inline float getThickness()  { return thickness; }

	/**
	 * This function is used to set the length of the wall.
	 * \param x Length of the wall
	 */
	inline void setLength(float x)  { length=x; }

	/// This function is used to return the length of the wall.
	inline float getLength() { return length; }

	/**
	 * This function is used to set the inner texture of the wall.
	 * \param i represents the inner texture of the wall that is to be set
	 */
	inline void setInnerTexture(const Texture &i) { innerTexture = i; };

	/// This function returns the value of the inner texture.
	inline const Texture &getInnerTexture() { return innerTexture; }

	/**
	 * This function is used to set the outer texture of the wall.
	 * \param o represents the outer texture of the wall that is to be set
	 */
	inline void setOuterTexture(const Texture &o) { outerTexture = o; };

	/// This function returns the outer texture of the wall.
	inline const Texture &getOuterTexture() { return outerTexture; }

	/** This function is used to add window in the wall.
	 * \param position It is the position where the window is to be placed on the wall
	 * \param length The length of the window
	 * \param texture The texture that should be loaded for the window
	 * \param lowerHeight The lower height of the window, default value is 3.0
	 * \param upperHeight The upper height of the window, default value is 7.0
	 */
	void addWindow(float position, float length, const Texture &texture = Texture(0x7F00FFFF), float lowerHeight = 3.0, float upperHeight = 7.0);

	/** This function is used to add door to a wall.
	 *  This function calls the \ref addWindow function with lowerHeight set to zero.
	 * \param position It is the position where the door is to be placed on the wall
	 * \param length The length of the door
	 * \param texture The texture of the door
	 * \param height The height of the door, default value of 7.0
	 */
	inline void addDoor(float position, float length, const Texture &texture = Texture(0x7F00FFFF), float height = 7.0)
	{
		addWindow(position, length, texture, 0.0f, height);
	}

	virtual void generateList();

	/// This function draws the objects and the windows
	virtual void drawObject();

    private:
	class Window;
	class Door;
	QList<Window *> windows;

	// This draws an inner and outer segment. Not for public consumption
	void drawSegment(float startx, float starty, float endx, float endy);
};

#endif
