#include "itempropertiesmodel.h"

#include <QStandardItemModel>
#include <QDomElement>

ItemPropertiesModel::ItemPropertiesModel(const QDomElement &e) : QStandardItemModel(), elem(e)
{
}
