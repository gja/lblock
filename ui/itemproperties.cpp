#include "itemproperties.h"
#include "ui_itemproperties.h"

#include <QDomElement>
#include <QDomDocument>
#include <QHash>

ItemPropertiesDialog::ItemPropertiesDialog(QWidget *parent) : QDialog(parent)
{
	ui = new Ui::ItemPropertiesDialog;
	ui->setupUi(this);
}

ItemPropertiesDialog::~ItemPropertiesDialog()
{
	delete ui;
}
