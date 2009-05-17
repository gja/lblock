#include "glbox.h"
#include "texture.h"
#include "wall.h"
#include "floor.h"
#include "table.h"
#include "constants.h"
#include "stairs.h"
#include "chair.h"
#include "bed.h"
#include "sofa.h"
#include "tv.h"
#include "lblockxmlengine.h"

#include <qgl.h>
#include <QImage>
#include <QDebug>

void GLBox::drawObject()
{
	QDomElement root = doc->documentElement().toElement();

	QDomElement texture1 = root.elementsByTagName("textures").item(0).toElement();

	for (QDomNode i = texture1.firstChild(); !i.isNull(); i = i.nextSibling())
	{
		QDomElement e = i.toElement();

		QString name = e.attribute("name");
		QString value = e.attribute("value");
		QString color = e.attribute("color", "0xFFFFFF");
		QString xscale = e.attribute("xscale", "1.0");
		QString yscale = e.attribute("yscale", "1.0");

		qDebug()<<"Adding Texture:"<<name<<color<<xscale<<yscale;
		textures[name] = Texture(color.toUInt(0, 16), QByteArray::fromBase64(value.toAscii()), xscale.toFloat(), yscale.toFloat());
	}

	for(QDomNode floor = root.elementsByTagName("floor").item(0).toElement(); !floor.isNull(); floor = floor.nextSibling()) {

		float offGround = floor.toElement().attribute("id").toInt() * FLOOR_HEIGHT;

		for (QDomNode i = floor.firstChild(); !i.isNull(); i = i.nextSibling())
		{
			QDomElement e = i.toElement();

			float x = e.attribute("x").toFloat();
			float y = offGround + e.attribute("y").toFloat();
			float z = e.attribute("z").toFloat();
			float rotation = e.attribute("rotation", "0.0").toFloat();
			QString type = e.attribute("type");

			if (type == "wall")
			{
				QString length = e.attribute("length");
				QString innerTexture = e.attribute("innerTexture");
				QString outerTexture = e.attribute("outerTexture");
				QString height = e.attribute("height", "10.0");
				QString thickness = e.attribute("thickness", "0.5");

				qDebug()<<"Adding Wall:"<<x<<y<<z<<rotation<<length<<innerTexture<<outerTexture<<height<<thickness;

				Wall *wall = new Wall(x, y, z, rotation, length.toFloat(), textures[innerTexture], textures[outerTexture], height.toFloat(), thickness.toFloat());

				// now we start parsing the windows
				for (QDomNode w = e.firstChild(); !w.isNull(); w = w.nextSibling()) {
					QDomElement tmp = w.toElement();

					if (tmp.tagName() == "window") {
						QString position = tmp.attribute("position");
						QString length = tmp.attribute("length");
						QString texture = tmp.attribute("texture");
						QString lowerHeight = tmp.attribute("lowerHeight", "3.0");
						QString upperHeight = tmp.attribute("upperHeight", "7.0");
						wall->addWindow(position.toFloat(), length.toFloat(), textures[texture], lowerHeight.toFloat(), upperHeight.toFloat());
						qDebug()<<"Added Window:"<<position<<length<<texture<<lowerHeight<<upperHeight;
					}
					else if (tmp.tagName() == "door") {
						QString position = tmp.attribute("position");
						QString length = tmp.attribute("length");
						QString texture = tmp.attribute("texture");
						QString height = tmp.attribute("height", "7.0");
						wall->addDoor(position.toFloat(), length.toFloat(), textures[texture], height.toFloat());
						qDebug()<<"Added Door:"<<position<<length<<texture<<height;
					}
				}

				addObject(wall);
			} else if (type == "floor") {
				QString lowerTexture = e.attribute("lowerTexture");
				QString upperTexture = e.attribute("upperTexture");
				QString length = e.attribute("length");
				QString width = e.attribute("width");
				QString thickness = e.attribute("thickness");
				qDebug()<<"Adding Floor:"<<x<<y<<z<<rotation<<length<<width<<lowerTexture<<upperTexture<<thickness;
				Floor *floor = new Floor(x, y, z, rotation, length.toFloat(), width.toFloat(), textures[upperTexture], textures[lowerTexture], thickness.toFloat());
				addObject(floor);
			}

			else if (type == "table") {
				QString width = e.attribute("width");
				QString length = e.attribute("length");
				QString height = e.attribute("height");
				QString texture = e.attribute("texture");

				Table *table = new Table(x, y, z, rotation, length.toFloat(), width.toFloat(), height.toFloat(), textures[texture]);

				addObject(table);
			}
			else if (type == "bed") {
				QString width = e.attribute("width");
				QString length = e.attribute("length");
				QString height = e.attribute("height");
				QString texture = e.attribute("texture");

				Bed *bed = new Bed(x, y, z, rotation, length.toFloat(), width.toFloat(), height.toFloat(), textures[texture]);

				addObject(bed);
			}

			else if (type == "sofa") {
				QString width = e.attribute("width");
				QString length = e.attribute("length");
				QString height = e.attribute("height");
				QString texture = e.attribute("texture");

				Sofa *sofa = new Sofa(x, y, z, rotation, length.toFloat(), width.toFloat(), height.toFloat(), textures[texture]);

				addObject(sofa);
			}

			else if (type == "stairs") {
				QString width = e.attribute("width");
				QString length = e.attribute("length");
				QString height = e.attribute("height");
				QString texture = e.attribute("texture");

				Stairs *stairs = new Stairs(x, y, z, rotation, length.toFloat(), width.toFloat(), height.toFloat(), textures[texture]);

				addObject(stairs);
			}

			else if (type == "tv") {
				QString width = e.attribute("width");
				QString length = e.attribute("length");
				QString height = e.attribute("height");
				QString texture = e.attribute("texture");

				Tv *tv = new Tv(x, y, z, rotation, length.toFloat(), width.toFloat(), height.toFloat(), textures[texture]);

				addObject(tv);
			}

			else if (type == "chair") {
				QString width = e.attribute("width");
				QString length = e.attribute("length");
				QString height = e.attribute("height");
				QString texture = e.attribute("texture");

				Chair *chair = new Chair(x, y, z, rotation, length.toFloat(), width.toFloat(), height.toFloat(), textures[texture]);

				addObject(chair);
			}
		}
	}
}
