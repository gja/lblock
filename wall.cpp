#include "wall.h"

#include <qgl.h>

Wall::Wall(float x, float y, float z, float r, float l, float h, float t) : Item (x, y, z, r) , length(l), height(h), thickness(t)
{
}

void Wall::generateList()
{
	glBegin(GL_QUADS);

		// Outer Wall
		glVertex3f(0.0f, 0.0f, 0.0f);
		glVertex3f(0.0f, height, 0.0f);
		glVertex3f(length, height, 0.0f);
		glVertex3f(length, 0.0f, 0.0f);

		// Inner Wall
		glVertex3f(0.0f, 0.0f, -thickness);
		glVertex3f(0.0f, height, -thickness);
		glVertex3f(length, height, -thickness);
		glVertex3f(length, 0.0f, -thickness);
	glEnd();
}
