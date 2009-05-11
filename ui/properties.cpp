#include "properties.h"
#include "ui_properties.h"

#include <QDomElement>
#include <QDomDocument>
#include <QHash>

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

	QDomElement floors = doc->documentElement().toElement().elementsByTagName("floors").item(0).toElement();
	QDomNodeList floorList = floors.elementsByTagName("floor");

	QHash <int, bool> createdFloors;

	for (int i = 0; i < floorList.count(); i++) {
		QDomNode floor = floorList.item(i);
		int floor_number = floor.toElement().attribute("id", "0").toInt();
		if (floor_number < ui->lowest->value() || floor_number > ui->highest->value())
			floors.removeChild(floor);
		else
			createdFloors[floor_number] = true;
	}

	for (int i = ui->lowest->value(); i <= ui->highest->value(); i++)
		if (! createdFloors[i]) {
			QDomElement elem = doc->createElement("floor");
			floors.appendChild(elem);
			elem.setAttribute("id", QString::number(i));
		}

	accept();
}

PropertiesDialog::~PropertiesDialog()
{
	delete ui;
}
