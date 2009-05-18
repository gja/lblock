#include "wall.h"
#include "window.h"
#include "door.h"

#include <qgl.h>
#include <QPoint>

Wall::Wall(float x, float y, float z, float r, float l, const Texture &i, const Texture &o, float h, float t) : Item (x, y, z, r) , length(l), innerTexture(i), outerTexture(o), height(h), thickness(t), collisionMatrix()
{
	collisionMatrix.rotate(-r);
	collisionMatrix.translate(-x, -z);
}

void Wall::addWindow(float p, float l, const Texture &t, float lh, float uh)
{
	Window *w = new Window(this, p, l, t, lh, uh);
	windows<<w;
}

void Wall::addDoor(float position, float length, const Texture &texture, float height)
{
	Door *d = new Door(this, position, length, texture, height);
	windows<<d;
}

Wall::~Wall()
{
	qDeleteAll(windows);
	windows.clear();
}

void Wall::drawSegment(float startx, float starty, float endx, float endy)
{
	// Outer Wall segment
	glBindTexture(GL_TEXTURE_2D, innerTexture.texture);
	glBegin(GL_QUADS);
		glTexCoord2f(startx / outerTexture.sizex, starty / outerTexture.sizey); glVertex3f(startx, starty, 0.0f);
		glTexCoord2f(startx / outerTexture.sizex, endy / outerTexture.sizey); glVertex3f(startx, endy, 0.0f);
		glTexCoord2f(endx / outerTexture.sizex, endy / outerTexture.sizey); glVertex3f(endx, endy, 0.0f);
		glTexCoord2f(endx / outerTexture.sizex, starty / outerTexture.sizey); glVertex3f(endx, starty, 0.0f);
	glEnd();

	// Inner Wall segment
	glBindTexture(GL_TEXTURE_2D, outerTexture.texture);
	glBegin(GL_QUADS);
		glTexCoord2f(startx / innerTexture.sizex, starty / innerTexture.sizey); glVertex3f(startx, starty, -thickness);
		glTexCoord2f(startx / innerTexture.sizex, endy / innerTexture.sizey); glVertex3f(startx, endy, -thickness);
		glTexCoord2f(endx / innerTexture.sizex, endy / innerTexture.sizey); glVertex3f(endx, endy, -thickness);
		glTexCoord2f(endx / innerTexture.sizex, starty / innerTexture.sizey); glVertex3f(endx, starty, -thickness);
	glEnd();
}

void Wall::generateList()
{
	QList <Window *> list = windows;
	Window *window;

	float startx = 0.0f; // Startx moves from left to right, drawing each window

	// For each window, we draw a solid wall till the window
	while (! list.isEmpty()) {
		window = list.takeFirst();

		// solid wall
		drawSegment(startx, 0.0f, window->position, height);

		// below, then above window
		drawSegment(window->position, 0.0f, window->position + window->length, window->lowerHeight);
		drawSegment(window->position, window->upperHeight, window->position + window->length, height);

		startx = window->position + window->length;
	}

	// The remaining part of the wall
	drawSegment(startx, 0.0f, length, height);

	// Side walls
	glBindTexture(GL_TEXTURE_2D, outerTexture.texture);
	glBegin(GL_QUADS);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(0.0f, 0.0f, -thickness);
		glTexCoord2f(0.0f, height / innerTexture.sizey); glVertex3f(0.0f, height, -thickness);
		glTexCoord2f(thickness / innerTexture.sizex, height / innerTexture.sizey); glVertex3f(0.0f, height, 0.0f);
		glTexCoord2f(thickness / innerTexture.sizex, 0.0f); glVertex3f(0.0f, 0.0f, 0.0f);

		glTexCoord2f(0.0f, 0.0f); glVertex3f(length, 0.0f, -thickness);
		glTexCoord2f(0.0f, height / innerTexture.sizey); glVertex3f(length, height, -thickness);
		glTexCoord2f(thickness / innerTexture.sizex, height / innerTexture.sizey); glVertex3f(length, height, 0.0f);
		glTexCoord2f(thickness / innerTexture.sizex, 0.0f); glVertex3f(length, 0.0f, 0.0f);
	glEnd();
}

void Wall::drawObject()
{
	if (dirty)
		compile();

	glPushMatrix();
	glTranslatef(posx, posy, posz);
	glRotatef(rotation, 0.0f, 1.0f, 0.0f);
	glCallList(object);

	foreach(Window *w, windows) {
		w->drawObject();
	}

	glPopMatrix();
}

bool Wall::isCollision(float x, float y, float z)
{
	if (y < posy || y > posy + height)
		return false;

	qreal newx, newz;

	collisionMatrix.map(x, z, &newx, &newz);

	foreach(Window *w, windows) {
		if (dynamic_cast<Door *>(w) && newx > w->position - 1.0 && newx < w->position + w->length + 1.0)
			return false;
	}

	if (newx >= -1.0 && newx <= length + 1.0 && newz >= -1.0 && newz <= thickness + 1.0)
		return true;
	return false;
}

