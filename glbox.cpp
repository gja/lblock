#include "glbox.h"
#include "constants.h"

#include <QDebug>
#include <QTimer>
#include <QKeyEvent>

#include <math.h>

// Create a GLBox widget
GLBox::GLBox( QWidget *parent) : QGLWidget(parent)
{
	posx = posy = posz = 0.0;
	left_right = up_down = 0;
}

// Release allocated resources
GLBox::~GLBox()
{
	makeCurrent();
	glDeleteLists(object, 1);
}

// Paint the box. The actual openGL commands for drawing the box are performed here.
void GLBox::paintGL()
{
	glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
	glLoadIdentity();

	// This next block changes the view
	double anglelr = left_right * M_PI / 180.;
	double angleud = up_down * M_PI / 180.;

	gluLookAt ( 	posx, posy, posz,
			posx + sin(anglelr), posy + sin(angleud), posz - cos(anglelr),
			0.0f, 1.0f, 0.0f);

	glCallList(object);
}


// Set up the OpenGL rendering state, and define display list
void GLBox::initializeGL()
{
	glClearColor(0.f, 0.f, 0.f, 0.f); 				// Let OpenGL clear to black
	glClearDepth(1.0f);
	glShadeModel( GL_SMOOTH );

	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);

	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

	object = glGenLists(1);
	glNewList(object, GL_COMPILE);
		void drawObject();
		drawObject();
	glEndList();
}

// Set up the OpenGL view port, matrix mode, etc.
void GLBox::resizeGL( int w, int h )
{
	glViewport( 0, 0, (GLint)w, (GLint)h );
	glMatrixMode( GL_PROJECTION );
	glLoadIdentity();
	gluPerspective(45.0, (double) w / (double) h, 1.0, 100.0);
	glMatrixMode( GL_MODELVIEW );
	glLoadIdentity();
}

void GLBox::keyPressEvent( QKeyEvent *e)
{
	switch( e->key() )
	{
		case Qt::Key_Escape:
			close();
			break;

		case Qt::Key_Left:
			left_right -= LEFT_RIGHT_STEP;
			if (left_right < 0)
				left_right += 360;
			break;

		case Qt::Key_Right:
			left_right += LEFT_RIGHT_STEP;
			if (left_right >= 360)
				left_right -= 360;
			break;

		case Qt::Key_PageUp:
			up_down += UP_DOWN_STEP;
			if (up_down > 60)
				up_down = 60;
			break;

		case Qt::Key_PageDown:
			up_down -= UP_DOWN_STEP;
			if (up_down < -60)
				up_down = -60;
			break;
	}

	updateGL();
}
