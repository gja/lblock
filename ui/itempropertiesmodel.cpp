#include "itempropertiesmodel.h"

#include <QStandardItemModel>
#include <QStandardItem>

inline void initializeModel(ItemPropertiesModel *t)
{
	t->setColumnCount(2);
	QStringList list;
	list<<"Property";
	list<<"Value";
	t->setHorizontalHeaderLabels(list);
}

#include <QDebug>
ItemPropertiesModel::ItemPropertiesModel(const LBlockValues &e) : QStandardItemModel(), elem(e)
{
	initializeModel(this);

	foreach(QString attribute, elem.keys()) {
		QStandardItem *row = new QStandardItem(attribute);
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
