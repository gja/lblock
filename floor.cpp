#include "floor.h"

#include <QList>
#include <QPointF>

#include <qgl.h>

void Floor::generateList()
{
	QList <QPointF> list = points;

	glBindTexture(GL_TEXTURE_2D, texture.texture);
	glBegin(GL_POLYGON);

	while ( ! list.isEmpty() ) {
		QPointF point = list.takeFirst();
		float x = point.x();
		float z = point.y();

		glTexCoord2f(x / texture.sizex, z / texture.sizey); glVertex3f(x, 0.0f, z);
	}

	glEnd();
}
