#include "textureslist.h"

#include <QStandardItemModel>
#include <QList>
#include <QStandardItem>
#include <QDomDocument>
#include <QDomElement>


void TexturesList::clear()
{
	QStandardItemModel::clear();
	qDeleteAll(items);
	items.clear();
}

TexturesList::TexturesList(QObject *parent) : QStandardItemModel(parent)
{
}

void TexturesList::parse()
{
	QDomElement root = doc->documentElement().toElement();

	QDomElement textures = root.elementsByTagName("textures").item(0).toElement();

	for (QDomNode i = textures.firstChild(); !i.isNull(); i = i.nextSibling())
	{
		QDomElement e = i.toElement();

		QString name = e.attribute("name");
		QString value = e.attribute("value");

		QByteArray array = QByteArray::fromBase64(value.toAscii());

		QPixmap pixmap;
		pixmap.loadFromData(array);

		QStandardItem *item = new QStandardItem(QIcon(pixmap), name);
		appendRow(item);
		items<<item;
	}
}
