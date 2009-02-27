#include "table.h"
#include "window.h"

#include <qgl.h>
#include <QPoint>

Table::Table(float x, float y, float z, float r, float l, float w, float h, const Texture &t) : Item (x, y, z, r) , length(l), texture(t), height(h), collisionMatrix(), width(w)
{
	collisionMatrix.rotate(-r);
	collisionMatrix.translate(-x, -z);
}

Table::~Table()
{
}

void Table::generateList()
{
	glBindTexture(GL_TEXTURE_2D, texture.texture);
	glBegin(GL_QUADS);

		// Top Edge
		glVertex3f(0.0f, height, 0.0f);
		glVertex3f(0.0f, height, length);
		glVertex3f(width, height, length);
		glVertex3f(width, height, 0.0f);

		glVertex3f(0.0f, height - 0.2f, 0.0f);
		glVertex3f(0.0f, height - 0.2f, length);
		glVertex3f(width, height - 0.2f, length);
		glVertex3f(width, height - 0.2f, 0.0f);
		
		//Sides covering the top two edges of the table
		glVertex3f(0.0f, height, 0.0f);
		glVertex3f(0.0f, height - 0.2f, 0.0f);
		glVertex3f(width, height - 0.2f, 0.0f);
		glVertex3f(width, height, 0.0f);

		glVertex3f(0.0f, height, 0.0f);
		glVertex3f(0.0f, height - 0.2f, 0.0f);
		glVertex3f(0.0f, height -0.2f, length);
		glVertex3f(0.0f, height, length);

		glVertex3f(0.0f, height, length);
		glVertex3f(0.0f, height - 0.2f, length);
		glVertex3f(width, height, length);
		glVertex3f(width, height - 0.2f, length);

		glVertex3f(width, height, length);
		glVertex3f(width, height - 0.2f, length);
		glVertex3f(width, height, 0.0f);
		glVertex3f(width, height - 0.2f, 0.0f);
		
		//Leg 1
		glVertex3f(0.0f, height - 0.2f, 0.0f);
		glVertex3f(0.0f, 0.0f, 0.0f);
		glVertex3f(0.2f, 0.0f, 0.0f);
		glVertex3f(0.2f, height - 0.2f, 0.0f);

		glVertex3f(0.0f, height - 0.2f, 0.0f);
		glVertex3f(0.0f, 0.0f, 0.0f);
		glVertex3f(0.0f, 0.0f, 0.2f);
		glVertex3f(0.0f, height - 0.2f, 0.2f);

		glVertex3f(0.0f, height - 0.2f, 0.2f);
		glVertex3f(0.0f, 0.0f, 0.2f);
		glVertex3f(0.2f, 0.0f, 0.2f);
		glVertex3f(0.2f, height - 0.2f, 0.2f);

		glVertex3f(0.2f, height - 0.2f, 0.2f);
		glVertex3f(0.2f, 0.0f, 0.2f);
		glVertex3f(0.2f, 0.0f, 0.0f);
		glVertex3f(0.2f, height - 0.2f, 0.0f);
		
		//Leg 2
		glVertex3f(0.0f, height - 0.2f, length - 0.2f);
		glVertex3f(0.0f, 0.0f, length - 0.2f);
		glVertex3f(0.2f, 0.0f, length - 0.2f);
		glVertex3f(0.2f, height - 0.2f, length - 0.2f);

		glVertex3f(0.0f, height - 0.2f, length - 0.2f);
		glVertex3f(0.0f, 0.0f, length - 0.2f);
		glVertex3f(0.0f, 0.0f, length);
		glVertex3f(0.0f, height - 0.2f, length);

		glVertex3f(0.0f, height - 0.2f, length);
		glVertex3f(0.0f, 0.0f, length);
		glVertex3f(0.2f, 0.0f, length);
		glVertex3f(0.2f, height - 0.2f, length);

		glVertex3f(0.2f, height - 0.2f, length);
		glVertex3f(0.2f, 0.0f, length);
		glVertex3f(0.2f, 0.0f, length - 0.2f);
		glVertex3f(0.2f, height - 0.2f, length - 0.2f);

		//Leg 3
		glVertex3f(width - 0.2f, height - 0.2f, length - 0.2f);
		glVertex3f(width - 0.2f, 0.0f, length - 0.2f);
		glVertex3f(width, 0.0f, length - 0.2f);
		glVertex3f(width, height - 0.2f, length - 0.2f);

		glVertex3f(width - 0.2f, height - 0.2f, length - 0.2f);
		glVertex3f(width - 0.2f, 0.0f, length - 0.2f);
		glVertex3f(width - 0.2f, 0.0f, length);
		glVertex3f(width - 0.2f, height - 0.2f, length);

		glVertex3f(width - 0.2f, height - 0.2f, length);
		glVertex3f(width - 0.2f, 0.0f, length);
		glVertex3f(width, 0.0f, length);
		glVertex3f(width, height - 0.2f, length);

		glVertex3f(width, height - 0.2f, length);
		glVertex3f(width, 0.0f, length);
		glVertex3f(width, 0.0f, length - 0.2f);
		glVertex3f(width, height - 0.2f, length - 0.2f);

		//Leg 4
		glVertex3f(width - 0.2f, height - 0.2f, 0.0f);
		glVertex3f(width - 0.2f, 0.0f, 0.0f);
		glVertex3f(width, 0.0f, 0.0f);
		glVertex3f(width, height - 0.2f, 0.0f);

		glVertex3f(width - 0.2f, height - 0.2f, 0.0f);
		glVertex3f(width - 0.2f, 0.0f, 0.0f);
		glVertex3f(width - 0.2f, 0.0f, 0.2f);
		glVertex3f(width - 0.2f, height - 0.2f, 0.2f);

		glVertex3f(width - 0.2f, height - 0.2f, 0.2f);
		glVertex3f(width - 0.2f, 0.0f, 0.2f);
		glVertex3f(width, 0.0f, 0.2f);
		glVertex3f(width, height - 0.2f, 0.2f);

		glVertex3f(width, height - 0.2f, 0.2f);
		glVertex3f(width, 0.0f, 0.2f);
		glVertex3f(width, 0.0f, 0.0f);
		glVertex3f(width, height - 0.2f, 0.0f);

	glEnd();
}

bool Table::isCollision(float x, float y, float z)
{
	if (y < posy || y > posy + height)
		return false;

	qreal newx, newz;

	collisionMatrix.map(x, z, &newx, &newz);

	if (newx >= -1.0 && newx <= length + 1.0 && newz >= -1.0 && newz <= width + 1.0)
		return true;
	return false;
}
