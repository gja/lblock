#include "itempropertiesmodel.h"

#include <QStandardItemModel>
#include <QDomElement>

ItemPropertiesModel::ItemPropertiesModel(const QDomElement &e) : QStandardItemModel(), elem(e)
{
	setColumnCount(2);
	QStringList list;
	list<<"Property";
	list<<"Value";
	setHorizontalHeaderLabels(list);
}

ItemPropertiesModel::ItemPropertiesModel() : QStandardItemModel()
{
	setColumnCount(2);
	QStringList list;
	list<<"Property";
	list<<"Value";
	setHorizontalHeaderLabels(list);
}
