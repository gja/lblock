#include "floor.h"

#include <QList>
#include <QPointF>

#include <qgl.h>

void Floor::generateList()
{
	// lower wall
	QList <QPointF> list = points;

	glBindTexture(GL_TEXTURE_2D, lowerTexture.texture);
	glBegin(GL_POLYGON);

	while ( ! list.isEmpty() ) {
		QPointF point = list.takeFirst();
		float x = point.x();
		float z = point.y();

		glTexCoord2f(x / lowerTexture.sizex, z / lowerTexture.sizey); glVertex3f(x, 0.0f, -z);
	}

	glEnd();

	// upper part
	list = points;

	glBindTexture(GL_TEXTURE_2D, upperTexture.texture);
	glBegin(GL_POLYGON);

	while ( ! list.isEmpty() ) {
		QPointF point = list.takeFirst();
		float x = point.x();
		float z = point.y();

		glTexCoord2f(x / upperTexture.sizex, z / upperTexture.sizey); glVertex3f(x, thickness, -z);
	}

	glEnd();
}
