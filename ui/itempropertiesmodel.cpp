#include "itempropertiesmodel.h"

#include <QStandardItemModel>
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

#include <QDebug>
ItemPropertiesModel::ItemPropertiesModel(const QDomElement &e) : QStandardItemModel(), elem(e)
{
	initializeModel(this);

	QDomNamedNodeMap attributes = elem.attributes();
	for (int i = 0; i < attributes.length(); i++) {
		QDomAttr item = attributes.item(i).toAttr();
		qDebug()<<item.name()<<item.value();
	}
}

ItemPropertiesModel::ItemPropertiesModel() : QStandardItemModel()
{
	initializeModel(this);
}
