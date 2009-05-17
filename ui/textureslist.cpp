#include "textureslist.h"

#include <QStandardItemModel>
#include <QList>
#include <QStandardItem>

void TexturesList::clear()
{
	qDeleteAll(items);
	QStandardItemModel::clear();
	items.clear();
}

TexturesList::TexturesList(LBlockXmlEngine *d, QObject *parent) : QStandardItemModel(parent)
{
	doc = d;
}

void TexturesList::parse()
{
	clear();

	LBlockValuesList list = doc->getTexturesList();
	
	foreach(LBlockValues texture, list) {
		QString name = texture["name"];
		QString value = texture["value"];

		QByteArray array = QByteArray::fromBase64(value.toAscii());

		QPixmap pixmap;
		pixmap.loadFromData(array);

		QStandardItem *item = new QStandardItem(QIcon(pixmap), name);
		appendRow(item);
		items<<item;
	}
}
