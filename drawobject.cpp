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
	QDomElement item = root.elementsByTagName("items").item(0).toElement();

	for (QDomNode i = texture1.firstChild(); !i.isNull(); i = i.nextSibling())
	{
		QDomElement e = i.toElement();	

		QString name, file, color, xscale, yscale;
		name = e.attribute("name");
		file = e.attribute("file");
		color = e.attribute("color", "0xFFFFFF");
		xscale = e.attribute("xscale", "1.0");
		yscale = e.attribute("yscale", "1.0");

		qDebug()<<name<<color<<file<<xscale<<yscale;
		textures[name] = Texture(color.toUInt(0, 16), file, xscale.toFloat(), yscale.toFloat());
	}
}
