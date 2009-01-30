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

		// Closest Wall
		wall = new Wall(-50.0f, i * 10.0f, 50.0f, 0.0f, 25.0f, textures["creamwall"], textures["maroon"]);
		wall->addWindow(1.0f, 4.0f, textures["window"], 4.0f, 7.0f);
		wall->addWindow(7.0f, 4.0f, textures["window"], 4.0f, 7.0f);
		wall->addWindow(13.0f, 4.0f, textures["window"], 4.0f, 7.0f);
		wall->addWindow(19.0f, 4.0f, textures["window"], 4.0f, 7.0f);
		addObject(wall);

		// Visible tall wall, inside of l
		wall = new Wall(-25.0f, i * 10.0f, 50.0f, 90.0f, 37.0f, textures["creamwall"], textures["maroon"]);
		wall->addWindow(1.0f, 4.0f, textures["window"], 4.0f, 7.0f);
		wall->addWindow(7.0f, 4.0f, textures["window"], 4.0f, 7.0f);
		wall->addWindow(13.0f, 4.0f, textures["window"], 4.0f, 7.0f);
		wall->addWindow(19.0f, 4.0f, textures["window"], 4.0f, 7.0f);
		wall->addWindow(25.0f, 4.0f, textures["window"], 4.0f, 7.0f);
		wall->addWindow(31.0f, 4.0f, textures["window"], 4.0f, 7.0f);
		addObject(wall);

		wall = new Wall(-31.0f, i * 10.0f, 87.0f, 180.0f, 19.0f, textures["creamwall"], textures["maroon"]);
		addObject(wall);

		wall = new Wall(-50.0f, i * 10.0f, 87.0f, 270.0f, 37.0f, textures["creamwall"], textures["maroon"]);
		addObject(wall);

		// Wall with doors
		wall = new Wall(-31.0f, i * 10.0f, 131.0f, 270.0f, 44.0f, textures["creamwall"], textures["maroon"]);
		// First Class Room
		wall->addWindow(6.0f, 5.0f, textures["darkwood"], 0.0f);
		wall->addWindow(13.0f, 4.0f, textures["window"]);
		wall->addWindow(19.0f, 4.0f, textures["window"]);
		// Second Class Room
		wall->addWindow(26.0f, 5.0f, textures["darkwood"], 0.0f);
		wall->addWindow(33.0f, 4.0f, textures["window"]);
		wall->addWindow(39.0f, 4.0f, textures["window"]);
		addObject(wall);

		// Railing Wall
		wall = new Wall(-25.0f, i * 10.0f, 87.0f, 90.0f, 44.0f, textures["creamwall"], i == 0 ? textures["maroon"] : textures["brown"], 4.0f);
		addObject(wall);

		// Pillars
		wall = new Wall(-25.0f, i * 10.0f + 4.0f, 100.0f, 90.0f, 2.0f, textures["creamwall"], textures["brown"], 6.0f);
		addObject(wall);
		wall = new Wall(-25.0f, i * 10.0f + 4.0f, 114.0f, 90.0f, 2.0f, textures["creamwall"], textures["brown"], 6.0f);
		addObject(wall);

		// Railing
		wall = new Wall(-25.0f, i* 10.0f + 4.25f, 87.0f, 90.0f, 13.0f, textures["black"], textures["black"], .25f);
		addObject(wall);
		wall = new Wall(-25.0f, i* 10.0f + 4.25f, 102.0f, 90.0f, 12.0f, textures["black"], textures["black"], .25f);
		addObject(wall);
		wall = new Wall(-25.0f, i* 10.0f + 4.25f, 116.0f, 90.0f, 15.0f, textures["black"], textures["black"], .25f);
		addObject(wall);

		// Main Door (at end of the hall)
		wall = new Wall(-31.0f, i * 10.0f, 87.0f, 0.0f, 5.5f, textures["creamwall"], textures["creamwall"]);
		wall->addWindow(1.0f, 4.0f, textures["darkwood"], 0.0f);
		addObject(wall);
		
		// Now the floors
		floor = new Floor(-50.0f, i * 10.0f, 50.0f, 0.0f, textures["marblefloor"], textures["creamwall"]);
		floor->addPoint(25.0f, 0.0f);
		floor->addPoint(25.0f, 37.0f);
		floor->addPoint(0.0f, 37.0f);
		addObject(floor);

		floor = new Floor(-31.0f, i * 10.0f, 87.0f, 0.0f, textures["marblefloor"], textures["creamwall"]);
		floor->addPoint(6.0f, 0.0f);
		floor->addPoint(6.0f, 44.0f);
		floor->addPoint(0.0f, 44.0f);
		addObject(floor);
	}

	wall = new Wall(-13.0f, 0.0f, -142.0f, 180.0f, 15.0f, textures["creamwall"], textures["maroon"]);
	addObject(wall);

	wall = new Wall(-32.0f, 0.0f, -142.0f, 231.0f, 5.0f, textures["creamwall"], textures["maroon"]);
	addObject(wall);

	wall = new Wall(-34.5f, 0.0f, -138.0f, 180.0f, 11.0f, textures["creamwall"], textures["maroon"]);
	addObject(wall);

	wall = new Wall(-45.5f, 0.0f, -138.0f, 270.0f, 7.0f, textures["creamwall"], textures["maroon"]);
	addObject(wall);

	wall = new Wall(-45.5f, 0.0f, -131.0f, 0.0f, 15.0f, textures["creamwall"], textures["maroon"]);
	addObject(wall);

	// Next, the right side

	// Finally, the enclave

	// Finally the sand
	floor = new Floor(-50.0f, 0.0f, 0.0f, 0.0f, textures["sand"]);
	floor->addPoint(25.0f, 0.0f);
	floor->addPoint(25.0f, 50.0f);
	floor->addPoint(0.0f, 50.0f);
	addObject(floor);

	floor = new Floor(-25.0f, 0.0f, 0.0f, 0.0f, textures["sand"]);
	floor->addPoint(100.0f, 0.0f);
	floor->addPoint(100.0f, 131.0f);
	floor->addPoint(0.0f, 131.0f);
	addObject(floor);
}
