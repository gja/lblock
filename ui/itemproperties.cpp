#include "itemproperties.h"
#include "ui_itemproperties.h"

#include <QDomElement>
#include <QDomDocument>
#include <QHash>

ItemPropertiesDialog::ItemPropertiesDialog(QWidget *parent) : QDialog(parent)
{
	ui = new Ui::ItemPropertiesDialog;
	ui->setupUi(this);

	model = new ItemPropertiesModel;
	ui->tableView->setModel(model);
}

ItemPropertiesDialog::~ItemPropertiesDialog()
{
	delete ui;
	delete model;
}

void ItemPropertiesDialog::setItem(const QDomElement &elem)
{
	if (model)
		delete model;

	model = new ItemPropertiesModel(elem);
	ui->tableView->setModel(model);
}
