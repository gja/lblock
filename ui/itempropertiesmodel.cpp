#include "itempropertiesmodel.h"

#include <QStandardItemModel>
#include <QDomElement>

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
}

ItemPropertiesModel::ItemPropertiesModel() : QStandardItemModel()
{
	initializeModel(this);
}
