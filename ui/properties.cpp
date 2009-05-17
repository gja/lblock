#include "properties.h"
#include "ui_properties.h"
#include "lblockxmlengine.h"


PropertiesDialog::PropertiesDialog(LBlockXmlEngine *d, QWidget *parent) : QDialog(parent), doc(d)
{
	ui = new Ui::PropertiesDialog;
	ui->setupUi(this);

	LBlockValues properties = doc->getProperties();

	ui->length->setValue(properties.value("length", "60").toInt());
	ui->width->setValue(properties.value("width", "40").toInt());
	ui->grid->setValue(properties.value("grid", "10").toInt());
	ui->lowest->setValue(properties.value("lowest", "0").toInt());
	ui->highest->setValue(properties.value("highest", "0").toInt());
}

void PropertiesDialog::slotVerifyAndAccept()
{

	if (ui->lowest->value() > ui->highest->value())
		return;

	LBlockValues elem = doc->getProperties();

	elem["length"] = QString::number(ui->length->value());
	elem["width"] = QString::number(ui->width->value());
	elem["grid"] = QString::number(ui->grid->value());
	elem["lowest"] = QString::number(ui->lowest->value());
	elem["highest"] = QString::number(ui->highest->value());
	elem.writeToElement();

	doc->ensureFloorsExist(ui->lowest->value(), ui->highest->value());

	accept();
}

PropertiesDialog::~PropertiesDialog()
{
	delete ui;
}
