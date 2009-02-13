#ifndef WALL_H
#define WALL_H

#include "item.h"
#include "texture.h"

#include <QList>
#include <QMatrix>

class Wall : public Item
{
    protected:
	GLfloat length;
	GLfloat height;
	GLfloat thickness;

	Texture innerTexture;
	Texture outerTexture;

	/// This stores the matrix for collision detection
	QMatrix collisionMatrix;

    public:
	// This is the Constructor
	Wall(float x, float y, float z, float rotation, float length, const Texture &inner = Texture(), const Texture &outer = Texture(), float height = 10.0f, float thickness = 0.5f);

	~Wall();

	// These two functions manipulate the height of the wall
	inline void setHeight(float x)  { height=x; }
	inline float getHeight()  { return height; }

	// These two functions helps manipulate the thickness of the wall
	inline void setThickness(float x)  { thickness=x;  }
	inline float getThickness()  { return thickness; }

	//These two functions manipulate the length of the wall
	inline void setLength(float x)  { length=x; }
	inline float getLength() { return length; }

	inline void setInnerTexture(const Texture &i) { innerTexture = i; };
	inline const Texture &getInnerTexture() { return innerTexture; }

	inline void setOuterTexture(const Texture &o) { outerTexture = o; };
	inline const Texture &getOuterTexture() { return outerTexture; }

	// This function is used to add a window
	// Remember to add windows in order from left -> right along the wall
	void addWindow(float position, float length, const Texture &texture = Texture(0x7F00FFFF), float lowerHeight = 3.0, float upperHeight = 7.0);

	virtual void generateList();

	/** This method checks if a point collides with this object
	 * \param x The X position of the point
	 * \param y The Y position of the point
	 * \param z The Z position of the point
	 * \return true if there is a collision, false otherwise
	 */
	virtual bool isCollision(float x, float y, float z);

    private:
	struct Window;
	QList<Window *> windows;

	// This draws an inner and outer segment. Not for public consumption
	void drawSegment(float startx, float starty, float endx, float endy);
};

#endif
