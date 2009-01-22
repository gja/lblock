#include "glbox.h"
#include <QDebug>
#include <QTimer>
#include <QKeyEvent>

// Create a GLBox widget
GLBox::GLBox( QWidget *parent) : QGLWidget(parent)
{
}

// Release allocated resources
GLBox::~GLBox()
{
	makeCurrent();
}

// Paint the box. The actual openGL commands for drawing the box are performed here.
void GLBox::paintGL()
{
	glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
	glLoadIdentity();
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
}

// Set up the OpenGL view port, matrix mode, etc.
void GLBox::resizeGL( int w, int h )
{

	glViewport( 0, 0, (GLint)w, (GLint)h );
	glMatrixMode( GL_PROJECTION );
	glLoadIdentity();
	glFrustum( -1.0, 1.0, -1.0, 1.0, 5.0, 20.0 );
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
	}
}
