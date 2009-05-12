#include "itempropertiesview.h"

#include <QListView>
#include <QMessageBox>
#include <QInputDialog>

ItemPropertiesView::ItemPropertiesView(QWidget *parent) : QListView(parent)
{
}

#include <QDebug>
void ItemPropertiesView::mouseDoubleClickEvent(QMouseEvent *event)
{
	QModelIndexList list = selectedIndexes();

	if (! list.isEmpty()) {
		QString name = list[0].data().toString();
		if (name != "type" && name != "name")
			emit modifyAttribute(name);
	}
}
