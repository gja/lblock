#include "chair.h"

#include <qgl.h>
#include <QPoint>

Chair::Chair(float x, float y, float z, float r, float l, float w, float h, const Texture &t) : Item (x, y, z, r) , length(l), texture(t), height(h), collisionMatrix(), width(w)
{
	collisionMatrix.rotate(-r);
	collisionMatrix.translate(-x, -z);
}

Chair::~Chair()
{
}

void Chair::generateList()
{
	glBindTexture(GL_TEXTURE_2D, texture.texture);
	glBegin(GL_QUADS);

		// Top Edge
		quickpoint(0.0f, (height / 2), 0.0f);
		quickpoint(0.0f, (height / 2), -width);
		quickpoint(length, (height / 2), -width);
		quickpoint(length, (height / 2), 0.0f);

		quickpoint(0.0f, (height / 2) - 0.2f, 0.0f);
		quickpoint(0.0f, (height / 2) - 0.2f, -width);
		quickpoint(length, (height / 2) - 0.2f, -width);
		quickpoint(length, (height / 2) - 0.2f, 0.0f);
		

		//Sides covering the top two edges of the table
		quickpoint(0.0f, (height / 2), 0.0f);
		quickpoint(0.0f, (height / 2) - 0.2f, 0.0f);
		quickpoint(length, (height / 2) - 0.2f, 0.0f);
		quickpoint(length, (height / 2), 0.0f);

		quickpoint(0.0f, (height / 2), 0.0f);
		quickpoint(0.0f, (height / 2) - 0.2f, 0.0f);
		quickpoint(0.0f, (height / 2) -0.2f, -width);
		quickpoint(0.0f, (height / 2), -width);

		quickpoint(0.0f, (height / 2), -width);
		quickpoint(0.0f, (height / 2) - 0.2f, -width);
		quickpoint(length, (height / 2), -width);
		quickpoint(length, (height / 2) - 0.2f, -width);

		quickpoint(length, (height / 2), -width);
		quickpoint(length, (height / 2) - 0.2f, -width);
		quickpoint(length, (height / 2), 0.0f);
		quickpoint(length, (height / 2) - 0.2f, 0.0f);
		
		//Leg 1
		quickpoint(0.0f, (height / 2) - 0.2f, 0.0f);
		quickpoint(0.0f, 0.0f, 0.0f);
		quickpoint(0.2f, 0.0f, 0.0f);
		quickpoint(0.2f, (height / 2) - 0.2f, 0.0f);

		quickpoint(0.0f, (height / 2) - 0.2f, 0.0f);
		quickpoint(0.0f, 0.0f, 0.0f);
		quickpoint(0.0f, 0.0f, -0.2f);
		quickpoint(0.0f, (height / 2) - 0.2f, -0.2f);

		quickpoint(0.0f, (height / 2) - 0.2f, -0.2f);
		quickpoint(0.0f, 0.0f, -0.2f);
		quickpoint(0.2f, 0.0f, -0.2f);
		quickpoint(0.2f, (height / 2) - 0.2f, -0.2f);

		quickpoint(0.2f, (height / 2) - 0.2f, -0.2f);
		quickpoint(0.2f, 0.0f, -0.2f);
		quickpoint(0.2f, 0.0f, 0.0f);
		quickpoint(0.2f, (height / 2) - 0.2f, 0.0f);
		
		//Leg 2
		quickpoint(0.0f, (height / 2) - 0.2f, -width + 0.2f);
		quickpoint(0.0f, 0.0f, -width + 0.2f);
		quickpoint(0.2f, 0.0f, -width + 0.2f);
		quickpoint(0.2f, (height / 2) - 0.2f, -width + 0.2f);

		quickpoint(0.0f, (height / 2) - 0.2f, -width + 0.2f);
		quickpoint(0.0f, 0.0f, -width + 0.2f);
		quickpoint(0.0f, 0.0f, -width);
		quickpoint(0.0f, (height / 2) - 0.2f, -width);

		quickpoint(0.0f, (height / 2) - 0.2f, -width);
		quickpoint(0.0f, 0.0f, -width);
		quickpoint(0.2f, 0.0f, -width);
		quickpoint(0.2f, (height / 2) - 0.2f, -width);

		quickpoint(0.2f, (height / 2) - 0.2f, -width);
		quickpoint(0.2f, 0.0f, -width);
		quickpoint(0.2f, 0.0f, -width + 0.2f);
		quickpoint(0.2f, (height / 2) - 0.2f, -width + 0.2f);

		//Leg 3
		quickpoint(length - 0.2f, (height / 2) - 0.2f, -width + 0.2f);
		quickpoint(length - 0.2f, 0.0f, -width + 0.2f);
		quickpoint(length, 0.0f, -width + 0.2f);
		quickpoint(length, (height / 2) - 0.2f, -width + 0.2f);

		quickpoint(length - 0.2f, (height / 2) - 0.2f, -width + 0.2f);
		quickpoint(length - 0.2f, 0.0f, -width + 0.2f);
		quickpoint(length - 0.2f, 0.0f, -width);
		quickpoint(length - 0.2f, (height / 2) - 0.2f, -width);

		quickpoint(length - 0.2f, (height / 2) - 0.2f, -width);
		quickpoint(length - 0.2f, 0.0f, -width);
		quickpoint(length, 0.0f, -width);
		quickpoint(length, (height / 2) - 0.2f, -width);

		quickpoint(length, (height / 2) - 0.2f, -width);
		quickpoint(length, 0.0f, -width);
		quickpoint(length, 0.0f, -width + 0.2f);
		quickpoint(length, (height / 2) - 0.2f, -width + 0.2f);

		//Leg 4
		quickpoint(length - 0.2f, (height / 2) - 0.2f, 0.0f);
		quickpoint(length - 0.2f, 0.0f, 0.0f);
		quickpoint(length, 0.0f, 0.0f);
		quickpoint(length, (height / 2) - 0.2f, 0.0f);

		quickpoint(length - 0.2f, (height / 2) - 0.2f, 0.0f);
		quickpoint(length - 0.2f, 0.0f, 0.0f);
		quickpoint(length - 0.2f, 0.0f, -0.2f);
		quickpoint(length - 0.2f, (height / 2) - 0.2f, -0.2f);

		quickpoint(length - 0.2f, (height / 2) - 0.2f, -0.2f);
		quickpoint(length - 0.2f, 0.0f, -0.2f);
		quickpoint(length, 0.0f, -0.2f);
		quickpoint(length, (height / 2) - 0.2f, -0.2f);

		quickpoint(length, (height / 2) - 0.2f, -0.2f);
		quickpoint(length, 0.0f, -0.2f);
		quickpoint(length, 0.0f, 0.0f);
		quickpoint(length, (height / 2) - 0.2f, 0.0f);

		// Back Rest
		quickpoint(0, (height / 2), -width);
		quickpoint(0, height, -width);
		quickpoint(length, height, -width);
		quickpoint(length, (height / 2), -width);

		quickpoint(0, (height / 2), -width + 0.2f);
		quickpoint(0, height, -width + 0.2f);
		quickpoint(length, height, -width + 0.2f);
		quickpoint(length, (height / 2), -width + 0.2f);

		quickpoint(0, (height / 2), -width);
		quickpoint(0, (height / 2), -width + 0.2f);
		quickpoint(0, height, -width + 0.2f);
		quickpoint(0, height, -width);

		quickpoint(length, (height / 2), -width);
		quickpoint(length, (height / 2), -width + 0.2f);
		quickpoint(length, height, -width + 0.2f);
		quickpoint(length, height, -width);
		
	glEnd();
}

bool Chair::isCollision(float x, float y, float z)
{
	if (y < posy || y > posy + height)
		return false;

	qreal newx, newz;

	collisionMatrix.map(x, z, &newx, &newz);

	if (newx >= -1.0 && newx <= length + 1.0 && newz >= -1.0 && newz <= width + 1.0)
		return true;
	return false;
}

