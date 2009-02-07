#ifndef WINDOW_H
#define WINDOW_H

#include <qgl.h>

#include "wall.h"
#include "item.h"

class Wall::Window : public Item
{
    protected:
	Wall *parent;
	GLfloat position;
	GLfloat length;
	Texture texture;
	GLfloat lowerHeight;
	GLfloat upperHeight;

	friend class Wall;

    public:
	// This is the constructor
	Window(Wall *parent, GLfloat pos, GLfloat length, const Texture &texture, GLfloat lowerHeight, GLfloat upperHeight);

	// This is the public function to draw the object
	virtual void drawObject();

	// This is the member which MUST be overridden, which generates the call list
	virtual void generateList();
};

#endif 
