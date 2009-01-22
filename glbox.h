#ifndef GLBOX_H
#define GLBOX_H

#include <qgl.h>

class QKeyEvent;

class GLBox : public QGLWidget
{
	Q_OBJECT

    public:
	GLBox( QWidget* parent = NULL);
	~GLBox();

    protected:
	void initializeGL();
	void paintGL();
	void resizeGL( int w, int h );

	// Called Whenever a Key is Pressed
	virtual void keyPressEvent( QKeyEvent *event );

	virtual void mouseMoveEvent( QMouseEvent *event);

	// This is a list to hold the object we are viewing
	GLuint object;

	// These next Few Parameters set what we are looking at
	// left_right and up_down are in degrees
	GLdouble posx, posy, posz;
	int left_right, up_down;

	// These next two variables are used to ensure that the mouse is in the center of the screen
	int centerx, centery;

    public slots:
};

#endif // GLBOX_H
