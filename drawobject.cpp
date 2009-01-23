#include "glbox.h"

#include <qgl.h>
#include <QImage>

// for color specifications, see http://www.december.com/html/spec/color1.html

void GLBox::loadAllTextures()
{
	initializeTexture( textures[0], "data/sand.png", 0xFFE303);
}

void GLBox::drawObject()
{
	glBegin(GL_QUADS);
		// First we start on sand
		qglColor ( Qt::white );
		glBindTexture(GL_TEXTURE_2D, textures[0]);

		glTexCoord2f(0.0f, 0.0f); glVertex3f( -24.0f, 0.0f, 10.0f);
		glTexCoord2f(0.0f, 3.0f); glVertex3f( -24.0f, 0.0f, -20.0f);
		glTexCoord2f(3.0f, 3.0f); glVertex3f( 64.0f, 0.0f, -20.0f);
		glTexCoord2f(3.0f, 0.0f); glVertex3f( 64.0f, 0.0f, 10.0f);

		glTexCoord2f(0.0f, 0.0f); glVertex3f( -4.0f, 0.0f, -20.0f);
		glTexCoord2f(0.0f, 3.0f); glVertex3f( -4.0f, 0.0f, -80.0f);
		glTexCoord2f(2.0f, 3.0f); glVertex3f( 64.0f, 0.0f, -80.0f);
		glTexCoord2f(2.0f, 0.0f); glVertex3f( 64.0f, 0.0f, -20.0f);

		// Now the actual lblock
		qglColor( QColor(0x822222));

		glVertex3f( -24.0f, 0.0f, -20.0f);
		glVertex3f( -24.0f, 20.0f, -20.0f);
		glVertex3f( -4.0f, 20.0f, -20.0f);
		glVertex3f( -4.0f, 0.0f, -20.0f);

		glVertex3f( -4.0f, 0.0f, -20.0f);
		glVertex3f( -4.0f, 20.0f, -20.0f);
		glVertex3f( -4.0f, 20.0f, -80.0f);
		glVertex3f( -4.0f, 0.0f, -80.0f);

		glVertex3f( -4.0f, 0.0f, -80.0f);
		glVertex3f( -4.0f, 20.0f, -80.0f);
		glVertex3f( 64.0f, 20.0f, -80.0f);
		glVertex3f( 64.0f, 0.0f, -80.0f);
	glEnd();
}
