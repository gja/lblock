#include "wall.h"

#include <qgl.h>

Wall::Wall(float x, float y, float z, float r, float l, const Texture &i, const Texture &o, float h, float t) : Item (x, y, z, r) , length(l), innerTexture(i), outerTexture(o), height(h), thickness(t)
{
}

void Wall::generateList()
{
	glBegin(GL_QUADS);

		// Outer Wall
		glBindTexture(GL_TEXTURE_2D, outerTexture.texture);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(0.0f, 0.0f, 0.0f);
		glTexCoord2f(0.0f, height / outerTexture.sizey); glVertex3f(0.0f, height, 0.0f);
		glTexCoord2f(length / outerTexture.sizex, height / outerTexture.sizey); glVertex3f(length, height, 0.0f);
		glTexCoord2f(length / outerTexture.sizex, 0.0f); glVertex3f(length, 0.0f, 0.0f);

		// Inner Wall
		glBindTexture(GL_TEXTURE_2D, innerTexture.texture);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(0.0f, 0.0f, -thickness);
		glTexCoord2f(0.0f, height / innerTexture.sizey); glVertex3f(0.0f, height, -thickness);
		glTexCoord2f(length / innerTexture.sizex, height / innerTexture.sizey); glVertex3f(length, height, -thickness);
		glTexCoord2f(length / innerTexture.sizex, 0.0f); glVertex3f(length, 0.0f, -thickness);

		// Side walls
		glTexCoord2f(0.0f, 0.0f); glVertex3f(0.0f, 0.0f, -thickness);
		glTexCoord2f(0.0f, height / outerTexture.sizey); glVertex3f(0.0f, height, -thickness);
		glTexCoord2f(thickness / outerTexture.sizex, height / outerTexture.sizey); glVertex3f(0.0f, height, 0.0f);
		glTexCoord2f(thickness / outerTexture.sizex, 0.0f); glVertex3f(0.0f, 0.0f, 0.0f);

		glTexCoord2f(0.0f, 0.0f); glVertex3f(length, 0.0f, -thickness);
		glTexCoord2f(0.0f, height / outerTexture.sizey); glVertex3f(length, height, -thickness);
		glTexCoord2f(thickness / outerTexture.sizex, height / outerTexture.sizey); glVertex3f(length, height, 0.0f);
		glTexCoord2f(thickness / outerTexture.sizex, 0.0f); glVertex3f(length, 0.0f, 0.0f);
	glEnd();
}
