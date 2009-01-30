#ifndef GLBOX_H
#define GLBOX_H

#include "texture.h"
#include "item.h"

#include <qgl.h>
#include <QHash>
#include <QString>

class QKeyEvent;

class GLBox : public QGLWidget
{
	Q_OBJECT

    private:
	inline void addObject(Item *item)
	{
		item->compile();
		model<<item;
	}

    public:
	GLBox( QWidget* parent = NULL);
	~GLBox();

    protected:
	void initializeGL();
	void paintGL();
	void resizeGL( int w, int h );

	// This is used to draw the current object
	virtual void drawObject();
	virtual void loadAllTextures();

	// Called Whenever a Key is Pressed
	virtual void keyPressEvent( QKeyEvent *event );

	virtual void mouseMoveEvent( QMouseEvent *event);

	// These next Few Parameters set what we are looking at
	// left_right and up_down are in degrees
	GLdouble posx, posy, posz;
	int left_right, up_down;

	// These next two variables are used to ensure that the mouse is in the center of the screen
	int centerx, centery;

	// This is a List of all the textures
	QHash <QString, Texture> textures;

	// List of all the items on screen
	QList <Item *> model;

    public slots:
};

#endif // GLBOX_H
