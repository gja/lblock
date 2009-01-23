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

		// Wall 1, Front Left
		glVertex3f( -24.0f, 0.0f, -20.0f);
		glVertex3f( -24.0f, 30.0f, -20.0f);
		glVertex3f( -4.0f, 30.0f, -20.0f);
		glVertex3f( -4.0f, 0.0f, -20.0f);

		// Wall 2, Side
		glVertex3f( -4.0f, 0.0f, -20.0f);
		glVertex3f( -4.0f, 30.0f, -20.0f);
		glVertex3f( -4.0f, 30.0f, -80.0f);
		glVertex3f( -4.0f, 0.0f, -80.0f);

		// Wall 3, Front, entrance
		glVertex3f( -4.0f, 0.0f, -80.0f);
		glVertex3f( -4.0f, 30.0f, -80.0f);
		glVertex3f( 64.0f, 30.0f, -80.0f);
		glVertex3f( 64.0f, 0.0f, -80.0f);

		// Add a few Windows
		// FIXME: this is a very ugly way to do it
		qglColor ( Qt::cyan );
		glVertex3f( -18.0f, 3.0f, -19.9f);
		glVertex3f( -18.0f, 7.0f, -19.9f);
		glVertex3f( -10.0f, 7.0f, -19.9f);
		glVertex3f( -10.0f, 3.0f, -19.9f);

		glVertex3f( -3.9f, 3.0f, -30.0f);
		glVertex3f( -3.9f, 3.0f, -38.0f);
		glVertex3f( -3.9f, 7.0f, -38.0f);
		glVertex3f( -3.9f, 7.0f, -30.0f);

		glVertex3f( -3.9f, 3.0f, -42.0f);
		glVertex3f( -3.9f, 3.0f, -50.0f);
		glVertex3f( -3.9f, 7.0f, -50.0f);
		glVertex3f( -3.9f, 7.0f, -42.0f);

		glVertex3f( -3.9f, 3.0f, -54.0f);
		glVertex3f( -3.9f, 3.0f, -62.0f);
		glVertex3f( -3.9f, 7.0f, -62.0f);
		glVertex3f( -3.9f, 7.0f, -54.0f);

		// entrance
		glVertex3f( 0.0f, 0.0f, -79.9f);
		glVertex3f( 0.0f, 15.0f, -79.9f);
		glVertex3f( 20.0f, 15.0f, -79.9f);
		glVertex3f( 20.0f, 0.0f, -79.9f);

		glVertex3f( 28.0f, 3.0f, -79.9f);
		glVertex3f( 28.0f, 7.0f, -79.9f);
		glVertex3f( 36.0f, 7.0f, -79.9f);
		glVertex3f( 36.0f, 3.0f, -79.9f);

		glVertex3f( 40.0f, 3.0f, -79.9f);
		glVertex3f( 40.0f, 7.0f, -79.9f);
		glVertex3f( 48.0f, 7.0f, -79.9f);
		glVertex3f( 48.0f, 3.0f, -79.9f);
	glEnd();
}
