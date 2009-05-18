#ifndef ITEMPROPERTIESMODEL_H
#define ITEMPROPERTIESMODEL_H

#include "lblockvalues.h"

#include <QStandardItemModel>
#include <QList>
/**
 * This class conatins the properties of the item in the model format.
 */
class ItemPropertiesModel : public QStandardItemModel {
	LBlockValues elem;
	/// This is th list of all the items
	QList<QStandardItem *> items;

    public:
    	/// This is the constuctor with paprameters
	ItemPropertiesModel(const LBlockValues &e);
	/// This is the empty constructor
	ItemPropertiesModel();

	~ItemPropertiesModel();
};

#endif
