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
	Wall *wall;

	wall = new Wall(-24.0f, 0.0f, -20.0f, 0.0f, 20.0f, textures["sand"], textures["maroon"]);
	wall->addWindow(6.0f, 8.0f, textures["glass"]);
	wall->compile();
	model<<wall;

	wall = new Wall(-4.0f, 0.0f, -20.0f, 90.0f, 60.0f, textures["sand"], textures["maroon"]);
	wall->addWindow(6.0f, 8.0f, textures["glass"]);
	wall->addWindow(20.0f, 8.0f, textures["glass"]);
	wall->addWindow(34.0f, 8.0f, textures["glass"]);
	wall->compile();
	model<<wall;

	wall = new Wall(-4.0f, 0.0f, -80.0f, 0.0f, 68.0f, textures["sand"], textures["maroon"]);
	wall->compile();
	model<<wall;

	Floor *floor = new Floor (-24.0f, 0.0f, 10.0f, 0.0f, textures["sand"]);
	floor->addPoint(88.0f, 0.0f);
	floor->addPoint(88.0f, -90.0f);
	floor->addPoint(20.0f, -90.0f);
	floor->addPoint(20.0f, -30.0f);
	floor->addPoint(0.0f, -30.0f);
	floor->compile();
	model<<floor;

	// entrance
	glVertex3f( 0.0f, 0.0f, -79.9f);
	glVertex3f( 0.0f, 15.0f, -79.9f);
	glVertex3f( 20.0f, 15.0f, -79.9f);
	glVertex3f( 20.0f, 0.0f, -79.9f);

	glVertex3f( 28.0f, 3.0f, -79.9f);
	glVertex3f( 28.0f, 7.0f, -79.9f);
	glVertex3f( 36.0f, 7.0f, -79.9f);
	glVertex3f( 36.0f, 3.0f, -79.9f);

	glVertex3f( 40.0f, 3.0f, -79.9f);
	glVertex3f( 40.0f, 7.0f, -79.9f);
	glVertex3f( 48.0f, 7.0f, -79.9f);
	glVertex3f( 48.0f, 3.0f, -79.9f);
}
