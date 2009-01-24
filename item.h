#ifndef ITEM_H
#define ITEM_H

class Item 
{
    protected:
	GLuint object;
	GLfloat posx, posy, posz;

    public:
	// This function is used to set the position of the object
	inline void setPos(float x,float y,float z) { posx=x; posy=y; posz=z; }

	// These next three functions return the position
	inline float getPosX() { return posx; }
	inline float getPosY() { return posy; }
	inline float getPosZ() { return posz; }
};

#endif 
