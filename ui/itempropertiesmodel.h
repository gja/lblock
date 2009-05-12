#ifndef ITEMPROPERTIESMODEL_H
#define ITEMPROPERTIESMODEL_H

#include <QStandardItemModel>
#include <QDomElement>
#include <QList>

class ItemPropertiesModel : public QStandardItemModel {
	QDomElement elem;

	QList<QStandardItem *> items;

    public:
	ItemPropertiesModel(const QDomElement &e);

	ItemPropertiesModel();

	~ItemPropertiesModel();
};

#endif
