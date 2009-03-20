#ifndef DOOR_H
#define DOOR_H

#include "window.h"

/// This Class represents a door. This class is identical to a Window, but has different defaults
class Wall::Door : public Wall::Window
{
    public:
	/**
	 * The Constructor.
	 * \param parent The Wall which has this doors
	 * \param pos The Position of the window
	 * \param length The length of the door
	 * \param texture The texture to be painted on the door
	 * \param height The height of the door
	 */
	inline Door(Wall *parent, GLfloat pos, GLfloat length, const Texture &texture, GLfloat height) : Window(parent, pos, length, texture, 0.0f, height)
	{
	}
}

#endif
