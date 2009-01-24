#ifndef TEXTURE_H
#define TEXTURE_H

#include <qgl.h>

struct Texture {
	GLuint texture;
	float sizex;
	float sizey;

	// Just a dummy constructor
	Texture();

	// The real constructor
	Texture(const char *path, const uint rgb = 0xFFFFFF, float x = 1.0f, float y = 1.0f);

	// This is called to free a texture. This is NOT a destructor, please call it manually
	void destroy();
};

#endif
