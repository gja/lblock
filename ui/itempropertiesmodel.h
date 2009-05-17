#ifndef ITEMPROPERTIESMODEL_H
#define ITEMPROPERTIESMODEL_H

#include "lblockvalues.h"

#include <QStandardItemModel>
#include <QList>

class ItemPropertiesModel : public QStandardItemModel {
	LBlockValues elem;

	QList<QStandardItem *> items;

    public:
	ItemPropertiesModel(const LBlockValues &e);

	ItemPropertiesModel();

	~ItemPropertiesModel();
};

#endif
