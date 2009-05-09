#include "stairs.h"

#include <qgl.h>
#include <QPoint>

Stairs::Stairs(float x, float y, float z, float r, float l, float w, float h, const Texture &t) : Item (x, y, z, r) , length(l), texture(t), height(h), collisionMatrix(), width(w)
{
	collisionMatrix.rotate(-r);
	collisionMatrix.translate(-x, -z);
}

Stairs::~Stairs()
{
}

void Stairs::generateList()
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
		
	

	glEnd();
}

bool Stairs::isCollision(float x, float y, float z)
{
	if (y < posy || y > posy + height)
		return false;

	qreal newx, newz;

	collisionMatrix.map(x, z, &newx, &newz);

	if (newx >= -1.0 && newx <= length + 1.0 && newz >= -1.0 && newz <= width + 1.0)
		return true;
	return false;
}
