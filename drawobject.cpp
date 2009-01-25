#include "glbox.h"
#include "texture.h"
#include "wall.h"
#include "floor.h"

#include <qgl.h>
#include <QImage>

// for color specifications, see http://www.december.com/html/spec/color1.html

void GLBox::loadAllTextures()
{
	textures["sand"] = Texture(0xFFE303, "data/sand.png", 8.0f, 8.0f);
	textures["maroon"] = Texture(0x822222);
	textures["glass"] = Texture(0xF000FFFF, "data/glass.png");
}

void GLBox::drawObject()
{
	// First, the left side of the building

	// Next, the right side
}
