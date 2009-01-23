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

	// This function is used to initalize a texture
	// The RGB values are used only if the image fails to load
	void initializeTexture(GLuint &texture_id, const char *path, const uint rgb = 0x000000);

	// This is used to draw the current object
	virtual void drawObject();
	virtual void loadAllTextures();

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

	// This is a List of all the textures
	// 0 - sand
	GLuint textures[10];

    public slots:
};

#endif // GLBOX_H
