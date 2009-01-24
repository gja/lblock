#ifndef ITEM_H
#define ITEM_H

#include <qgl.h>

class Item 
{
    protected:
	GLuint object;
	GLfloat posx, posy, posz;
	GLfloat rotation;

    public:
	// This is the constructor
	Item(float x, float y, float z, float rotation = 0.0f);

	// This function is used to set the position of the object
	inline void setPos(float x,float y,float z) { posx=x; posy=y; posz=z; }

	// These next three functions return the position
	inline float getPosX() { return posx; }
	inline float getPosY() { return posy; }
	inline float getPosZ() { return posz; }

	// This is used to set and get the rotation
	inline float getRotation() { return rotation; }
	inline void setRotation(float r) { rotation = r; }

	// This function MUST be overridden in every Item Class
	virtual void compile() = 0;

	virtual void drawObject();
};

#endif 
