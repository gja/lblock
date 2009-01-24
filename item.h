#ifndef ITEM_H
#define ITEM_H

class Item 
{

    protected:

	GLuint object;
  	GLfloat posx, posy, poz;

    public:

	inline void setPos(float x,float y,float z) { posx=x; posy=y; posz=z; }
	inline float getPosX() { return posx; }
	inline float getPosY() { return posy; }
	inline float getPosZ() { return posz; }
	

      		
};

#endif 
