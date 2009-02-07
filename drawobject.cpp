#include "glbox.h"
#include "texture.h"
#include "wall.h"
#include "floor.h"

#include <qgl.h>
#include <QImage>
#include <QDomDocument>
#include <QDebug>

void GLBox::drawObject(const QDomDocument &doc)
{
	QDomElement root = doc.documentElement().toElement();

	QDomElement texture1 = root.elementsByTagName("textures").item(0).toElement();

	for (QDomNode i = texture1.firstChild(); !i.isNull(); i = i.nextSibling())
	{
		QDomElement e = i.toElement();

		QString name = e.attribute("name");
		QString file = e.attribute("file");
		QString color = e.attribute("color", "0xFFFFFF");
		QString xscale = e.attribute("xscale", "1.0");
		QString yscale = e.attribute("yscale", "1.0");

		qDebug()<<"Adding Texture:"<<name<<color<<file<<xscale<<yscale;
		textures[name] = Texture(color.toUInt(0, 16), file, xscale.toFloat(), yscale.toFloat());
	}

	QDomElement item = root.elementsByTagName("items").item(0).toElement();

	for (QDomNode i = item.firstChild(); !i.isNull(); i = i.nextSibling())
	{
		QDomElement e = i.toElement();

		QString x = e.attribute("x");
		QString y = e.attribute("y");
		QString z = e.attribute("z");
		QString rotation = e.attribute("rotation", "0.0");
		QString type = e.attribute("type");

		if (type == "wall")
		{
			QString length = e.attribute("length");
			QString innerTexture = e.attribute("innerTexture");
			QString outerTexture = e.attribute("outerTexture");
			QString height = e.attribute("height", "10.0");
			QString thickness = e.attribute("thickness", "0.5");

			qDebug()<<"Adding Wall:"<<x<<y<<z<<rotation<<length<<innerTexture<<outerTexture<<height<<thickness;

			Wall *wall = new Wall(x.toFloat(), y.toFloat(), z.toFloat(), rotation.toFloat(), length.toFloat(), textures[innerTexture], textures[outerTexture], height.toFloat(), thickness.toFloat());
			addObject(wall);
		}
	}
}
