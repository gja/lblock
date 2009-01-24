#include "item.h"

#include <qgl.h>

void Item::drawObject()
{
	glPushMatrix();
	glTranslatef(posx, posy, posz);
	glRotatef(rotation, 0.0f, 1.0f, 0.0f);
	glCallList(object);
	glPopMatrix();
}

Item::Item(float x, float y, float z, float r) : posx(x) , posy(y), posz(z), rotation(r)
{
}

Item::~Item()
{
	glDeleteLists(object, 1);
}

void Item::compile()
{
	object = glGenLists(1);
	glNewList(object, GL_COMPILE);
		generateList();
	glEndList();
}
