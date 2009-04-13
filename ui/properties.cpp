#include "properties.h"
#include "ui_properties.h"

#include <QDomElement>
#include <QDomDocument>

PropertiesDialog::PropertiesDialog(QDomDocument *d, QWidget *parent) : QDialog(parent), doc(d)
{
	ui = new Ui::PropertiesDialog;
	ui->setupUi(this);

	QDomElement properties = doc->documentElement().toElement().elementsByTagName("properties").item(0).toElement();

	ui->length->setValue(properties.attribute("length", "60").toInt());
	ui->width->setValue(properties.attribute("width", "40").toInt());
	ui->grid->setValue(properties.attribute("grid", "10").toInt());
	ui->lowest->setValue(properties.attribute("lowest", "0").toInt());
	ui->highest->setValue(properties.attribute("highest", "0").toInt());
}

void PropertiesDialog::slotVerifyAndAccept()
{

	if (ui->lowest->value() > ui->highest->value())
		return;

	QDomElement elem = doc->documentElement().toElement().elementsByTagName("properties").item(0).toElement();

	elem.setAttribute("length", ui->length->value());
	elem.setAttribute("width", ui->width->value());
	elem.setAttribute("grid", ui->grid->value());
	elem.setAttribute("lowest", ui->lowest->value());
	elem.setAttribute("highest", ui->highest->value());

	accept();
}

PropertiesDialog::~PropertiesDialog()
{
	delete ui;
}
