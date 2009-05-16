#include "floor.h"

#include <QList>
#include <QPointF>

#include <qgl.h>

void Floor::generateList()
{
	// lower side
	glBindTexture(GL_TEXTURE_2D, lowerTexture.texture);
	glBegin(GL_QUADS);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(0.0f, 0.0f, -0.0f);
		glTexCoord2f(0.0f, width / lowerTexture.sizey); glVertex3f(0.0f, 0.0f, -width);
		glTexCoord2f(length / lowerTexture.sizex, width / lowerTexture.sizey); glVertex3f(length, 0.0f, -width);
		glTexCoord2f(length / lowerTexture.sizex, 0.0f); glVertex3f(length, 0.0f, 0.0f);
	glEnd();

	// upper side
	glBindTexture(GL_TEXTURE_2D, upperTexture.texture);
	glBegin(GL_QUADS);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(0.0f, 0.0f, -0.0f);
		glTexCoord2f(0.0f, width / lowerTexture.sizey); glVertex3f(0.0f, 0.0f, -width);
		glTexCoord2f(length / lowerTexture.sizex, width / lowerTexture.sizey); glVertex3f(length, 0.0f, -width);
		glTexCoord2f(length / lowerTexture.sizex, 0.0f); glVertex3f(length, 0.0f, 0.0f);
	glEnd();
}
