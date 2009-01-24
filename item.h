#ifndef ITEM_H
#define ITEM_H

class item 
{

    protected:
   	GLuint object;
 	GLfloat posx, posy, poz;
    public:
   	inline void setPos(float x,float y,float z) { posx=x; posy=y; posz=z; }
      inline void getPosx() { return posx; }
 	inline void getPosy() { return posy; }
	inline void getPosz() { return posz; }
	
   	
};

#endif 
