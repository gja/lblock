#ifndef ITEM_H
#define ITEM_H

#include <qgl.h>

class Item 
{
    protected:
	// This stores the OpenGL Display List
	GLuint object;

	// This is the positions and rotation of the object
	GLfloat posx, posy, posz;
	GLfloat rotation;

	// Set this to 1 to force a recompile next time we draw
	bool dirty;

    public:
	// This is the constructor
	Item(float x, float y, float z, float rotation = 0.0f);

	// The Destructor
	~Item();

	// This function is used to set the position of the object
	inline void setPos(float x,float y,float z) { posx=x; posy=y; posz=z; }

	// These next three functions return the position
	inline float getPosX() { return posx; }
	inline float getPosY() { return posy; }
	inline float getPosZ() { return posz; }

	// This is used to set and get the rotation
	inline float getRotation() { return rotation; }
	inline void setRotation(float r) { rotation = r; }

	// This function generates a callList
	virtual void compile();

	// This is the public function to draw the object
	virtual void drawObject();

	// This is the member which MUST be overridden, which generates the call list
	virtual void generateList() = 0;

	/** This method checks if a point collides with this object
	 * \param x The X position of the point
	 * \param y The Y position of the point
	 * \param z The Z position of the point
	 * \return true if there is a collision, false otherwise
	 */
	virtual bool isCollision(float x, float y, float z);
};

#endif 
