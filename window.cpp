#include "item.h"
#include "window.h"

#include <qgl.h>

Wall::Window::Window(Wall *w, GLfloat p, GLfloat l, const Texture &t, GLfloat lh, GLfloat uh) : parent(w), Item(w->posx, w->posy, w->posz, w->rotation), position(p), length(l), texture(t), lowerHeight(lh), upperHeight(uh)
{
}

void Wall::Window::drawObject()
{
	if (dirty)
		compile();

	// Assume we are already positioned within a wall
	glPushMatrix();
	glTranslatef(position, 0.0f, 0.0f);
	glCallList(object);
	glPopMatrix();
}

void Wall::Window::generateList()
{
	glBindTexture(GL_TEXTURE_2D, texture.texture);
	glBegin(GL_QUADS);
		glTexCoord2f(0.0, 0.0); glVertex3f(0.0f, lowerHeight, 0.0f);
		glTexCoord2f(0.0, 1.0); glVertex3f(0.0f, upperHeight, 0.0f);
		glTexCoord2f(1.0, 1.0); glVertex3f(length, upperHeight, 0.0f);
		glTexCoord2f(1.0, 0.0); glVertex3f(length, lowerHeight, 0.0f);

		glTexCoord2f(0.0, 0.0); glVertex3f(0.0f, lowerHeight, -parent->thickness);
		glTexCoord2f(0.0, 1.0); glVertex3f(0.0f, upperHeight, -parent->thickness);
		glTexCoord2f(1.0, 1.0); glVertex3f(length, upperHeight, -parent->thickness);
		glTexCoord2f(1.0, 0.0); glVertex3f(length, lowerHeight, -parent->thickness);
	glEnd();
}
