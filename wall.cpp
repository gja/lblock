#include "wall.h"

#include <qgl.h>

Wall::Wall(float x, float y, float z, float r, float l, const Texture &i, const Texture &o, float h, float t) : Item (x, y, z, r) , length(l), innerTexture(i), outerTexture(o), height(h), thickness(t)
{
}

struct Wall::Window {
	float position;
	float length;
	float upperHeight;
	float lowerHeight;
	Texture texture;

	inline Window (float p, float l, const Texture &t, float lh, float uh)
		: position(p), length(l), upperHeight(uh), lowerHeight(lh), texture(t)
	{}
};

void Wall::addWindow(float p, float l, const Texture &t, float lh, float uh)
{
	windows << new Window(p, l, t, lh, uh);
}

Wall::~Wall()
{
	while (! windows.isEmpty())
		delete windows.takeFirst();
}

void Wall::drawSegment(float startx, float starty, float endx, float endy)
{
	// Outer Wall segment
	glBindTexture(GL_TEXTURE_2D, outerTexture.texture);
	glBegin(GL_QUADS);
		glTexCoord2f(startx / outerTexture.sizex, starty / outerTexture.sizey); glVertex3f(startx, starty, 0.0f);
		glTexCoord2f(startx / outerTexture.sizex, endy / outerTexture.sizey); glVertex3f(startx, endy, 0.0f);
		glTexCoord2f(endx / outerTexture.sizex, endy / outerTexture.sizey); glVertex3f(endx, endy, 0.0f);
		glTexCoord2f(endx / outerTexture.sizex, starty / outerTexture.sizey); glVertex3f(endx, starty, 0.0f);
	glEnd();

	// Inner Wall segment
	glBindTexture(GL_TEXTURE_2D, innerTexture.texture);
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

		// now that window itself not that in the innertexture side, the image is reversed
		glBindTexture(GL_TEXTURE_2D, window->texture.texture);
		glBegin(GL_QUADS);
			glTexCoord2f(0.0, 0.0); glVertex3f(window->position, window->lowerHeight, 0.0f);
			glTexCoord2f(0.0, 1.0); glVertex3f(window->position, window->upperHeight, 0.0f);
			glTexCoord2f(1.0, 1.0); glVertex3f(window->position + window->length, window->upperHeight, 0.0f);
			glTexCoord2f(1.0, 0.0); glVertex3f(window->position + window->length, window->lowerHeight, 0.0f);

			glTexCoord2f(0.0, 0.0); glVertex3f(window->position, window->lowerHeight, -thickness);
			glTexCoord2f(0.0, 1.0); glVertex3f(window->position, window->upperHeight, -thickness);
			glTexCoord2f(1.0, 1.0); glVertex3f(window->position + window->length, window->upperHeight, -thickness);
			glTexCoord2f(1.0, 0.0); glVertex3f(window->position + window->length, window->lowerHeight, -thickness);
		glEnd();

		startx = window->position + window->length;
	}

	// The remaining part of the wall
	drawSegment(startx, 0.0f, length, height);

	// Side walls
	glBindTexture(GL_TEXTURE_2D, innerTexture.texture);
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
