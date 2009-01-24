#ifndef WALL_H
#define WALL_H
#include "item.h"


class Wall : public Item
{
  
    protected:

  	GLuint object;
 	GLfloat height;
 	GLfloat thickness;

    public:

	inline void setHeight(float x)  { height=x; }
 	inline float getHeight()  { return height; }
	inline void setThickness(float x)  { thickness=x;  }
	inline float getThickness()  { return thickness; }
		
};

#endif