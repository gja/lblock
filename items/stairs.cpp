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
	float i = 0;
	float j = 0;

	while(i<height)
	{
		quickpoint(0, i, -j);
		quickpoint(0, i, -j - width / 9);
		quickpoint(length, i, -j - width / 9);
		quickpoint(length, i, -j);

		quickpoint(0, i, -j - width/9);
		quickpoint(0, i + height/9, -j - width/9);
		quickpoint(length, i + height/9, -j - width/9);
		quickpoint(length, i, -j - width/9);
		
		i = i + height/9;
		j = j + width/9;
	}
	

	glEnd();
}

bool Stairs::isCollision(float x, float y, float z)
{
	return false;
}
