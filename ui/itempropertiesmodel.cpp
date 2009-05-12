#include "itempropertiesmodel.h"

#include <QStandardItemModel>
#include <QStandardItem>
#include <QDomElement>
#include <QDomNode>
#include <QDomNamedNodeMap>

inline void initializeModel(ItemPropertiesModel *t)
{
	t->setColumnCount(2);
	QStringList list;
	list<<"Property";
	list<<"Value";
	t->setHorizontalHeaderLabels(list);
}

ItemPropertiesModel::ItemPropertiesModel(const QDomElement &e) : QStandardItemModel(), elem(e)
{
	initializeModel(this);

	QDomNamedNodeMap attributes = elem.attributes();
	for (int i = 0; i < attributes.length(); i++) {
		QDomAttr item = attributes.item(i).toAttr();
		QStandardItem *row = new QStandardItem(item.name());
		row->setEditable(false);
		items<<row;
		appendRow(row);
	}
}

ItemPropertiesModel::ItemPropertiesModel() : QStandardItemModel()
{
	initializeModel(this);
}

ItemPropertiesModel::~ItemPropertiesModel()
{
	qDeleteAll(items);
	items.clear();
}
