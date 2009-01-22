#include <qgl.h>

void drawObject()
{
	glBegin(GL_QUADS);
		glVertex3f(-1.0f, -1.0f, -5.0f);
		glVertex3f(-1.0f, 1.0f, -5.0f);
		glVertex3f(1.0f, 1.0f, -5.0f);
		glVertex3f(1.0f, -1.0f, -5.0f);
	glEnd();
}
