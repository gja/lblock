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
	textures["black"] = Texture(0x000000);
}

void GLBox::drawObject()
{
	Wall *wall;
	Floor *floor;
	
	// First, the left side of the building
	for (int i = 0; i < 3; i++) {
		wall = new Wall(-50.0f, i * 10.0f, -50.0f, 0.0f, 25.0f, textures["creamwall"], textures["maroon"]);
		wall->addWindow(1.0f, 4.0f, textures["window"], 4.0f, 7.0f);
		wall->addWindow(7.0f, 4.0f, textures["window"], 4.0f, 7.0f);
		wall->addWindow(13.0f, 4.0f, textures["window"], 4.0f, 7.0f);
		wall->addWindow(19.0f, 4.0f, textures["window"], 4.0f, 7.0f);
		addObject(wall);

		wall = new Wall(-25.0f, i * 10.0f, -50.0f, 90.0f, 37.0f, textures["creamwall"], textures["maroon"]);
		wall->addWindow(1.0f, 4.0f, textures["window"], 4.0f, 7.0f);
		wall->addWindow(7.0f, 4.0f, textures["window"], 4.0f, 7.0f);
		wall->addWindow(13.0f, 4.0f, textures["window"], 4.0f, 7.0f);
		wall->addWindow(19.0f, 4.0f, textures["window"], 4.0f, 7.0f);
		wall->addWindow(25.0f, 4.0f, textures["window"], 4.0f, 7.0f);
		wall->addWindow(31.0f, 4.0f, textures["window"], 4.0f, 7.0f);
		addObject(wall);

		wall = new Wall(-31.0f, i * 10.0f, -87.0f, 180.0f, 19.0f, textures["creamwall"], textures["maroon"]);
		addObject(wall);

		wall = new Wall(-50.0f, i * 10.0f, -87.0f, 270.0f, 37.0f, textures["creamwall"], textures["maroon"]);
		addObject(wall);

		wall = new Wall(-31.0f, i * 10.0f, -131.0f, 270.0f, 44.0f, textures["creamwall"], textures["maroon"]);
		addObject(wall);

		wall = new Wall(-25.0f, i * 10.0f, -87.0f, 90.0f, 44.0f, textures["creamwall"], textures["maroon"], 4.0f);
		addObject(wall);

		wall = new Wall(-25.0f, i* 10.0f + 4.25f, -87.0f, 90.0f, 44.0f, textures["black"], textures["black"], .25f);
		addObject(wall);
		
		floor = new Floor(-50.0f, i * 10.0f, -50.0f, 0.0f, textures["creamwall"], textures["marblefloor"]);
		floor->addPoint(25.0f, 0.0f);
		floor->addPoint(25.0f, 37.0f);
		floor->addPoint(25.0f, 81.0f);
		floor->addPoint(19.0f, 81.0f);
		floor->addPoint(19.0f, 37.0f);
		floor->addPoint(0.0f, 37.0f);
		addObject(floor);
	}

	// Wall which railing is on + the railing

	// Next, the right side
}
