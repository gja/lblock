#include "itemproperties.h"
#include "ui_itemproperties.h"

#include <QInputDialog>

ItemPropertiesDialog::ItemPropertiesDialog(QWidget *parent) : QDialog(parent)
{
	ui = new Ui::ItemPropertiesDialog;
	ui->setupUi(this);

	model = new ItemPropertiesModel;
	ui->view->setModel(model);
}

ItemPropertiesDialog::~ItemPropertiesDialog()
{
	delete ui;
	delete model;
}

void ItemPropertiesDialog::setItem(const LBlockValues &e)
{
	elem = e;

	if (model)
		delete model;

	model = new ItemPropertiesModel(elem);
	ui->view->setModel(model);
}

void ItemPropertiesDialog::slotModifyAttribute(const QString &name)
{
	QString value = QInputDialog::getText(this, "Edit Attribute", QString("Enter Value for ") + name, QLineEdit::Normal, elem[name]);
	elem[name] = value;
	elem.writeToElement();
	emit dirty();
}
