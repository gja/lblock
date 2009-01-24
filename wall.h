#ifndef WALL_H
#define WALL_H

#include "item.h"

class Wall : public Item
{
    protected:
	GLfloat length;
	GLfloat height;
	GLfloat thickness;

    public:
	// This is the Constructor
	Wall(float x, float y, float z, float rotation, float length, float height = 10.0f, float thickness = 0.5f);

	// These two functions manipulate the height of the wall
	inline void setHeight(float x)  { height=x; }
	inline float getHeight()  { return height; }

	// These two functions helps manipulate the thickness of the wall
	inline void setThickness(float x)  { thickness=x;  }
	inline float getThickness()  { return thickness; }

	//These two functions manipulate the length of the wall
	inline void setLength(float x)  { length=x; }
	inline float getLength() { return length; }

	virtual void generateList();
};

#endif
