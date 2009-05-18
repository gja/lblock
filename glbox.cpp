#include "glbox.h"
#include "constants.h"
#include "wall.h"
#include "lblockxmlengine.h"

#include <QTimer>
#include <QKeyEvent>
#include <QApplication>
#include <QDesktopWidget>
#include <QDebug>

#include <QFile>

#include <math.h>

// Create a GLBox widget
GLBox::GLBox(LBlockXmlEngine *d, QWidget *parent) : QGLWidget(parent), doc(d)
{
	LBlockValues properties = doc->getProperties();
	posx = properties["startx"].toInt();
	posz = -properties["starty"].toInt();

	posy = 6.0;		// 6 foot tall, caught you red handed!
	left_right = up_down = 0;

	setCursor( Qt::CrossCursor);
	setMouseTracking(true);

	centerx = QApplication::desktop()->width() / 2;
	centery = QApplication::desktop()->height() / 2;

	connect(&timer, SIGNAL(timeout()), this, SLOT(updateGL()));
	timer.setInterval(50);
}

// Release allocated resources
GLBox::~GLBox()
{
	makeCurrent();
	qDeleteAll(model);
	model.clear();
}

// Paint the box. The actual openGL commands for drawing the box are performed here.
void GLBox::paintGL()
{
	QCursor::setPos(centerx, centery);

	glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
	glLoadIdentity();

	// This next block changes the view
	double anglelr = left_right * M_PI / 180.;
	double angleud = up_down * M_PI / 180.;

	gluLookAt ( 	posx, posy, posz,
			posx + sin(anglelr), posy + sin(angleud), posz - cos(anglelr),
			0.0f, 1.0f, 0.0f);

	qglColor( Qt::white );	

	// Draw all the objects
	QList <Item *> list = model;
	Item *item;
	while (! list.isEmpty() )
		list.takeFirst()->drawObject();
}


// Set up the OpenGL rendering state, and define display list
void GLBox::initializeGL()
{
	glClearColor(0.f, 0.f, 0.f, 0.f); 				// Let OpenGL clear to black
	glClearDepth(1.0f);
	glShadeModel( GL_SMOOTH );

	glEnable(GL_TEXTURE_2D);
	glShadeModel(GL_SMOOTH);

	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);

	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

	drawObject();

	timer.start();
}

// Set up the OpenGL view port, matrix mode, etc.
void GLBox::resizeGL( int w, int h )
{
	glViewport( 0, 0, (GLint)w, (GLint)h );
	glMatrixMode( GL_PROJECTION );
	glLoadIdentity();
	gluPerspective(45.0, (double) w / (double) h, 1.0, 1000.0);
	glMatrixMode( GL_MODELVIEW );
	glLoadIdentity();
}

void GLBox::keyPressEvent( QKeyEvent *e)
{
	double angle = left_right * M_PI / 180.;
	float newposx = posx, newposz = posz;

	switch( e->key() )
	{
		case ESCAPE_KEY:
			close();
			break;

		case LOOK_LEFT_KEY:
			left_right -= LEFT_RIGHT_STEP;
			if (left_right < 0)
				left_right += 360;
			break;

		case LOOK_RIGHT_KEY:
			left_right += LEFT_RIGHT_STEP;
			if (left_right >= 360)
				left_right -= 360;
			break;

		case LOOK_UP_KEY:
			up_down += UP_DOWN_STEP;
			if (up_down > MAX_LOOKUP)
				up_down = 60;
			break;

		case LOOK_DOWN_KEY:
			up_down -= UP_DOWN_STEP;
			if (up_down < -MAX_LOOKUP)
				up_down = -60;
			break;

		case MOVE_FORWARD_KEY:
			newposx += WALK_STEP * sin(angle);
			newposz -= WALK_STEP * cos(angle);
			break;

		case MOVE_BACKWARD_KEY:
			newposx -= WALK_STEP * sin(angle);
			newposz += WALK_STEP * cos(angle);
			break;

		case MOVE_LEFT_KEY:
			newposx -= WALK_STEP * cos(angle);
			newposz -= WALK_STEP * sin(angle);
			break;

		case MOVE_RIGHT_KEY:
			newposx += WALK_STEP * cos(angle);
			newposz += WALK_STEP * sin(angle);
			break;

		case MOVE_UP_KEY:
			posy += WALK_STEP;
			break;

		case MOVE_DOWN_KEY:
			posy -= WALK_STEP;
			break;

		case Qt::Key_Space:
			qDebug()<<posx<<posy<<posz<<left_right<<up_down;
	}

	// If we have a collision, then don't move
	foreach(Item *item, model) {
		if (item->isCollision(newposx, posy, -newposz))
			return;
	}
	posx = newposx;
	posz = newposz;
}

void GLBox::mouseMoveEvent (QMouseEvent *event)
{
	// If this is just us recentering the mouse, exit
	if (event->pos() == QPoint( centerx, centery) )
		return;

	left_right += (event->x() - centerx) / 8;
	up_down -= (event->y() - centery) / 8;

	if (left_right >= 360)
		left_right -= 360;
	else if (left_right < 0)
		left_right += 360;

	if (up_down > 60)
		up_down = 60;
	else if (up_down < -60)
		up_down = -60;
}

void GLBox::closeEvent(QCloseEvent *event)
{
	setMouseTracking(false);
	emit(terminated());
}
