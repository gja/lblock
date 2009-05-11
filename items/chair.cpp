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
		glVertex3f(0.0f, height/2, 0.0f);
		glVertex3f(0.0f, height/2, length/2);
		glVertex3f(width, height/2, length/2);
		glVertex3f(width, height/2, 0.0f);

		glVertex3f(0.0f, (height - 0.2f)/2, 0.0f);
		glVertex3f(0.0f, (height - 0.2f)/2, length/2);
		glVertex3f(width, (height - 0.2f)/2, length/2);
		glVertex3f(width, (height - 0.2f)/2, 0.0f);
		
		//Sides covering the top two edges of the table
		glVertex3f(0.0f, height/2, 0.0f);
		glVertex3f(0.0f, (height - 0.2f)/2, 0.0f);
		glVertex3f(width, (height - 0.2f)/2, 0.0f);
		glVertex3f(width, height/2, 0.0f);

		glVertex3f(0.0f, height/2, 0.0f);
		glVertex3f(0.0f, (height - 0.2f)/2, 0.0f);
		glVertex3f(0.0f, (height -0.2f)/2, length/2);
		glVertex3f(0.0f, height/2, length/2);

		glVertex3f(0.0f, height/2, length/2);
		glVertex3f(0.0f, (height - 0.2f)/2, length/2);
		glVertex3f(width, height/2, length/2);
		glVertex3f(width, (height - 0.2f)/2, length/2);

		glVertex3f(width, height/2, length/2);
		glVertex3f(width, (height - 0.2f)/2, length/2);
		glVertex3f(width, height/2, 0.0f);
		glVertex3f(width, (height - 0.2f)/2, 0.0f);
		
		//Leg 1
		glVertex3f(0.0f, (height - 0.2f)/2, 0.0f);
		glVertex3f(0.0f, 0.0f, 0.0f);
		glVertex3f(0.2f, 0.0f, 0.0f);
		glVertex3f(0.2f, (height - 0.2f)/2, 0.0f);

		glVertex3f(0.0f, (height - 0.2f)/2, 0.0f);
		glVertex3f(0.0f, 0.0f, 0.0f);
		glVertex3f(0.0f, 0.0f, 0.2f);
		glVertex3f(0.0f, (height - 0.2f)/2, 0.1f);

		glVertex3f(0.0f, (height - 0.2f)/2, 0.1f);
		glVertex3f(0.0f, 0.0f, 0.1f);
		glVertex3f(0.2f, 0.0f, 0.1f);
		glVertex3f(0.2f, (height - 0.2f)/2, 0.1f);

		glVertex3f(0.2f, (height - 0.2f)/2, 0.1f);
		glVertex3f(0.2f, 0.0f, 0.1f);
		glVertex3f(0.2f, 0.0f, 0.0f);
		glVertex3f(0.2f, (height - 0.2f)/2, 0.0f);
		
		//Leg 2
		glVertex3f(0.0f, (height - 0.2f)/2, (length - 0.2f)/2);
		glVertex3f(0.0f, 0.0f, (length - 0.2f)/2);
		glVertex3f(0.2f, 0.0f, (length - 0.2f)/2);
		glVertex3f(0.2f, (height - 0.2f)/2, (length - 0.2f)/2);

		glVertex3f(0.0f, (height - 0.2f)/2, (length - 0.2f)/2);
		glVertex3f(0.0f, 0.0f, (length - 0.2f)/2);
		glVertex3f(0.0f, 0.0f, length/2);
		glVertex3f(0.0f, (height - 0.2f)/2, length/2);

		glVertex3f(0.0f, (height - 0.2f)/2, length/2);
		glVertex3f(0.0f, 0.0f, length/2);
		glVertex3f(0.2f, 0.0f, length/2);
		glVertex3f(0.2f, (height - 0.2f)/2, length/2);

		glVertex3f(0.2f, (height - 0.2f)/2, length/2);
		glVertex3f(0.2f, 0.0f, length/2);
		glVertex3f(0.2f, 0.0f, (length - 0.2f)/2);
		glVertex3f(0.2f, (height - 0.2f)/2, (length - 0.2f)/2);

		//Leg 3
		glVertex3f(width - 0.2f, (height - 0.2f)/2, (length - 0.2f)/2);
		glVertex3f(width - 0.2f, 0.0f, (length - 0.2f)/2);
		glVertex3f(width, 0.0f, (length - 0.2f)/2);
		glVertex3f(width, (height - 0.2f)/2, (length - 0.2f)/2);

		glVertex3f(width - 0.2f, (height - 0.2f)/2, (length - 0.2f)/2);
		glVertex3f(width - 0.2f, 0.0f, (length - 0.2f)/2);
		glVertex3f(width - 0.2f, 0.0f, length/2);
		glVertex3f(width - 0.2f, (height - 0.2f)/2, length/2);

		glVertex3f(width - 0.2f, (height - 0.2f)/2, length/2);
		glVertex3f(width - 0.2f, 0.0f, length/2);
		glVertex3f(width, 0.0f, length/2);
		glVertex3f(width, (height - 0.2f)/2, length/2);

		glVertex3f(width, (height - 0.2f)/2, length/2);
		glVertex3f(width, 0.0f, length/2);
		glVertex3f(width, 0.0f, (length - 0.2f)/2);
		glVertex3f(width, (height - 0.2f)/2, (length - 0.2f)/2);

		//Leg 4
		glVertex3f(width - 0.2f, (height - 0.2f)/2, 0.0f);
		glVertex3f(width - 0.2f, 0.0f, 0.0f);
		glVertex3f(width, 0.0f, 0.0f);
		glVertex3f(width, (height - 0.2f)/2, 0.0f);

		glVertex3f(width - 0.2f, (height - 0.2f)/2, 0.0f);
		glVertex3f(width - 0.2f, 0.0f, 0.0f);
		glVertex3f(width - 0.2f, 0.0f, 0.1f);
		glVertex3f(width - 0.2f, (height - 0.2f)/2, 0.1f);

		glVertex3f(width - 0.2f, (height - 0.2f)/2, 0.1f);
		glVertex3f(width - 0.2f, 0.0f, 0.1f);
		glVertex3f(width, 0.0f, 0.1f);
		glVertex3f(width, (height - 0.2f)/2, 0.1f);

		glVertex3f(width, (height - 0.2f)/2, 0.1f);
		glVertex3f(width, 0.0f, 0.1f);
		glVertex3f(width, 0.0f, 0.0f);
		glVertex3f(width, (height - 0.2f)/2, 0.0f);

		//Backrest
		glVertex3f(width, height/2, length/2);
		glVertex3f(width, (height + 5.0f)/2, length/2);
		glVertex3f(width, (height + 5.0f)/2, (length - 10.0f)/2);
		glVertex3f(width, height/2, (length - 10.0f)/2);

		
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

