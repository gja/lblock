#include "glbox.h"
#include "texture.h"
#include "wall.h"
#include "floor.h"

#include <qgl.h>
#include <QImage>

// for color specifications, see http://www.december.com/html/spec/color1.html

void GLBox::loadAllTextures()
{
	textures["sand"] = Texture(0xCBAB88, "data/sand.png", 8.0f, 8.0f);
	textures["maroon"] = Texture(0xB87353, "data/maroon.png");
	textures["glass"] = Texture(0xF000FFFF, "data/glass.png");
	textures["window"] = Texture(0xF000FFFF, "data/window.png");
	textures["brown"] = Texture(0xBFAA82, "data/brown.png");
	textures["creamwall"] = Texture(0xA2865D, "data/creamwall.png");
	textures["lightwood"] = Texture(0xAB8560, "data/lightwood.png");
	textures["darkwood"] = Texture(0x653626, "data/darkwood.png");
	textures["marblefloor"] = Texture(0x8B8C8D, "data/marblefloor.png");
}

void GLBox::drawObject()
{
	// First, the left side of the building

	// Next, the right side
}
