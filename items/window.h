#ifndef WINDOW_H
#define WINDOW_H

#include <qgl.h>

#include "wall.h"
#include "item.h"

/**
 * This class represents a window. There is never any need to access this
 * class directly. Objects of this class are added via the \ref addWindow()
 * method of the \ref Wall class. The scale of the texture is not honored
 * in this function. It is stretched to the size of the window.
 */
class Wall::Window : public Item
{
    protected:	

	/// This holds a pointer to the wall in which this wall is embedded
	Wall *parent;
	
	/// This holds the position (from the start of the wall)
	GLfloat position;

	/// This holds the length of the window
	GLfloat length;

	/// This holds the image of the texture. This is drawn straight forward on
	/// the outer wall, and backwards on the inner wall
	Texture texture;

	/// This holds the height of the lower edge of the wall (above the wall's 0)
	GLfloat lowerHeight;

	/// This holds the height of the upper edge of the wall (above the wall's 0)
	GLfloat upperHeight;

	/// Members from this class are accessed transparently from Wall
	friend class Wall;

    public:
	/**
	 * This is the constructor
	 * \param parent The Wall which has this windows
	 * \param pos The Position of the Window
	 * \param length The length of the window
	 * \param texture The texture to be painted on the window
	 * \param lowerHeight The height of the lower edge of the window
	 * \param upperHeight The height of the upper edge of the window
	 */
	Window(Wall *parent, GLfloat pos, GLfloat length, const Texture &texture, GLfloat lowerHeight, GLfloat upperHeight);

	/// This is the public function to draw the window
	virtual void drawObject();

	/// This generates the call list to draw the window
	virtual void generateList();
};

#endif 
