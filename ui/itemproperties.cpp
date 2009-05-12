#include "itemproperties.h"
#include "ui_itemproperties.h"

#include <QDomElement>
#include <QInputDialog>
#include <QDomDocument>
#include <QHash>

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

void ItemPropertiesDialog::setItem(const QDomElement &e)
{
	elem = e;

	if (model)
		delete model;

	model = new ItemPropertiesModel(elem);
	ui->view->setModel(model);
}

void ItemPropertiesDialog::slotModifyAttribute(const QString &name)
{
	QString value = QInputDialog::getText(this, "Edit Attribute", QString("Enter Value for ") + name, QLineEdit::Normal, elem.attribute(name));
	elem.setAttribute(name, value);
	emit dirty();
}
