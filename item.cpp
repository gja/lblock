#include "item.h"

#include <qgl.h>

void Item::drawObject()
{
	if (dirty)
		compile();

	glPushMatrix();
	glTranslatef(posx, posy, posz);
	glRotatef(rotation, 0.0f, 1.0f, 0.0f);
	glCallList(object);
	glPopMatrix();
}

Item::Item(float x, float y, float z, float r) : posx(x) , posy(y), posz(-z), rotation(r), dirty(true), object(0)
{
}

Item::~Item()
{
	glDeleteLists(object, 1);
}

void Item::compile()
{
	if (glIsList(object))
		glDeleteLists(object, 1);

	object = glGenLists(1);
	glNewList(object, GL_COMPILE);
		generateList();
	glEndList();
	dirty = false;
}

bool Item::isCollision(float x, float y, float z)
{
	return 0;
}
