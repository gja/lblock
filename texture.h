#ifndef TEXTURE_H
#define TEXTURE_H

#include <qgl.h>

/**
 * This represents all the functions used for loading a texture.
 * An object of this model can be used to set the textures of a wall.
 */
struct Texture {

	/// This stores the texture in an OpenGL format after reading it to memory
	GLuint texture;

	/// This stores the width of the texture in feet.
	float sizex;

	/// This stores the height of the texture in feet.
	float sizey;

	/// Just a dummy constructor
	Texture();

	/**
	 *  This is the constructor.
	 *  This initializes the texture, for future use
	 *  \param rgb a default colour that is to be loaded 
	 *  \param path specifies where the texture file that is to be loaded is present
	 *  \param x gives the x scale, default value is 1.0
	 *  \param y gives the y scale, default value is 1.0 
	 *  \param readfile states whether to read the file, or we are passing the value as base64
	 */ 
	Texture(const uint rgb, const QString &path = QString(), float x = 1.0f, float y = 1.0f, bool readfile = false);

	/// This is the destructor
	void destroy();
};

#endif
