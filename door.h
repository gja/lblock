#ifndef DOOR_H
#define DOOR_H

#include "window.h"

class Wall::Door : public Wall::Window
{
    public:
	inline Door(Wall *parent, GLfloat pos, GLfloat length, const Texture &texture, GLfloat height) : Window(parent, pos, length, texture, 0.0f, height)
	{
	}
}

#endif
