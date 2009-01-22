#include "glbox.h"

#include <qgl.h>

void GLBox::drawObject()
{
	glBegin(GL_QUADS);
		qglColor( Qt::white ); glVertex3f(-1.0f, 5.0f, -5.0f);
		qglColor( Qt::red ); glVertex3f(-1.0f, 7.0f, -5.0f);
		qglColor( Qt::blue ); glVertex3f(1.0f, 7.0f, -5.0f);
		qglColor( Qt::green ); glVertex3f(1.0f, 5.0f, -5.0f);

		qglColor( Qt::darkYellow);
		glVertex3f(-1.0f, 0.0f, 0.0f);
		glVertex3f(-1.0f, 0.0f, -30.0f);
		glVertex3f(10.0f, 0.0f, -30.0f);
		glVertex3f(10.0f, 0.0f, 0.0f);
	glEnd();
}
