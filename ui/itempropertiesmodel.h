#ifndef ITEMPROPERTIESMODEL_H
#define ITEMPROPERTIESMODEL_H

#include <QStandardItemModel>
#include <QDomElement>

class ItemPropertiesModel : public QStandardItemModel {
	QDomElement elem;

    public:
	ItemPropertiesModel(const QDomElement &e);
};

#endif
