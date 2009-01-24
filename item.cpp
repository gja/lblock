#include "item.h"

#include <qgl>

void Item::drawObject()
{
	glPushMatrix();
	glTranslatef(posx, posy, posz);
	glRotatef(rotation, 0.0f, 1.0f, 0.0f);
	glCallList(object);
	glPopMatrix();
}
