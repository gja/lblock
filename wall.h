#ifndef WALL_H
#define WALL_H
#include "item.h"


class wall : public item
{
  
  	protected:
  		GLuint object;
 		GLfloat height;
 		GLfloat thickness;
	public:
		inline void setHeight(float x)  { height=x; }
 		inline void getHeight()  { return height; }
		inline void setThickness(float x)  { thickness=x;  }
		inline void getThickness()  { return thickness; }
		
};

#endif