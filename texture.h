#ifndef TEXTURE_H
#define TEXTURE_H

#include <qgl.h>

struct Texture {
	GLuint texture;
	float sizex;
	float sizey;

	// Just a dummy constructor
	Texture();

	// The real constructor. At the Minimum, this needs a backup value as argb
	Texture(const uint rgb, const QString &path = QString(), float x = 1.0f, float y = 1.0f);

	// This is called to free a texture. This is NOT a destructor, please call it manually
	void destroy();
};

#endif
