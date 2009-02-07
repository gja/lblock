#ifndef WALL_H
#define WALL_H

#include "item.h"
#include "texture.h"

#include <QList>

class Wall : public Item
{
    protected:
	GLfloat length;
	GLfloat height;
	GLfloat thickness;

	Texture innerTexture;
	Texture outerTexture;

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

	// This function is used to add a window/door
	// Remember to add windows/doors in order from left -> right along the wall
	void addWindow(float position, float length, const Texture &texture = Texture(0x7F00FFFF), float lowerHeight = 3.0, float upperHeight = 7.0);
	inline void addDoor(float position, float length, const Texture &texture = Texture(0x7F00FFFF), float height = 7.0)
	{
		addWindow(position, length, texture, 0.0f, height);
	}

	virtual void generateList();

	// This draws the objects and the windows
	virtual void drawObject();

    private:
	class Window;
	class Door;
	QList<Window *> windows;

	// This draws an inner and outer segment. Not for public consumption
	void drawSegment(float startx, float starty, float endx, float endy);
};

#endif
