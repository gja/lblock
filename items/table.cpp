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
		glVertex3f(0.0f, height, 0.0f);
		glVertex3f(0.0f, height, length);
		glVertex3f(width, height, length);
		glVertex3f(width, height, 0.0f);
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
