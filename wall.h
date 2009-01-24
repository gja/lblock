#ifndef WALL_H
#define WALL_H

#include "item.h"

class Wall : public Item
{
    protected:
	GLfloat height;
	GLfloat thickness;

    public:

	// These two functions manipulate the height of the wall
	inline void setHeight(float x)  { height=x; }
	inline float getHeight()  { return height; }

	// These two functions helps manipulate the thickness of the wall
	inline void setThickness(float x)  { thickness=x;  }
	inline float getThickness()  { return thickness; }
};

#endif
