#include "ui_edittexture.h"
#include "edittexture.h"

#include <qmath.h>

#include <QFileDialog>
#include <QBuffer>
#include <QColorDialog>
#include <QPalette>

ModifyTexture::ModifyTexture(LBlockXmlEngine *d, QWidget *parent) : QDialog(parent), doc(d)
{
	ui = new Ui::EditTexture();
	ui->setupUi(this);
}

ModifyTexture::~ModifyTexture()
{
	delete ui;
}

inline void SetButtonColor(QPushButton *button, QColor color)
{
	QPalette palette = button->palette();
	palette.setColor(QPalette::Button, color);
	button->setPalette(palette);
}

void ModifyTexture::slotChangeColor()
{
	QColor c(color.toUInt(0, 16));

	QColor newcolor = QColorDialog::getColor(c, this);

	if (newcolor.isValid()) {
		color = QString("0x") + QString::number(newcolor.rgb(), 16).toUpper();
		SetButtonColor(ui->colorButton, newcolor);
	}
}

inline int power_of_two_floor(qreal value)
{
	return (unsigned) qPow( 2, qFloor( qLn( value ) / qLn( 2 ) ) );
}

void ModifyTexture::slotChangeImage()
{
	QString name = QFileDialog::getOpenFileName(this, "Open File...", QString(), "Image Files (*.png *.jpg *.bmp)");

	if (name.isEmpty())
		return;

	QPixmap pixmap(name);

	if (pixmap.isNull()) {
		emit(error("Error, Unable to Read Image"));
	}

	int width = power_of_two_floor(pixmap.width());
	int height = power_of_two_floor(pixmap.height());

	QPixmap newPixmap = pixmap.scaled(width, height);
	ui->preview->setPixmap(newPixmap);

	QByteArray array;
	QBuffer buffer(&array);
	buffer.open(QIODevice::WriteOnly);
	newPixmap.save(&buffer, "PNG");

	value = array.toBase64();
}

EditTexture::EditTexture(QString n, LBlockXmlEngine *doc, QWidget *parent) : ModifyTexture(doc, parent), elem()
{
	elem = doc->getTexture(n);

	name = n;
	value = elem.value("value");
	color = elem.value("color", "0xFFFFFF");
	xscale = elem.value("xscale", "1.0");
	yscale = elem.value("yscale", "1.0");

	QByteArray array = QByteArray::fromBase64(value.toAscii());

	QPixmap pixmap;
	pixmap.loadFromData(array);

	ui->name->setText(name);
	ui->preview->setPixmap(pixmap);
	ui->xscale->setValue(xscale.toDouble());
	ui->yscale->setValue(yscale.toDouble());

	ui->imageButton->setEnabled(false);
	ui->name->setReadOnly(true);

	SetButtonColor(ui->colorButton, color.toUInt(0, 16));
}

void EditTexture::slotVerifyAndAccept()
{
	xscale = QString::number(ui->xscale->value());
	yscale = QString::number(ui->yscale->value());

	elem["xscale"] = xscale;
	elem["yscale"] = yscale;
	elem["color"] = color;
	elem.writeToElement();

	accept();
}

NewTexture::NewTexture(LBlockXmlEngine *doc, QWidget *parent) : ModifyTexture(doc, parent)
{
}

void NewTexture::slotVerifyAndAccept()
{
	name = ui->name->text();
	xscale = QString::number(ui->xscale->value());
	yscale = QString::number(ui->yscale->value());

	if (name.isEmpty() || value.isEmpty()) {
		// Error, not complete

		return;
	}

	LBlockValues elem;
	elem["name"] = name;
	elem["value"] = value;
	elem["xscale"] = xscale;
	elem["yscale"] = yscale;
	elem["color"] = color;

	doc->addTexture(elem);

	accept();
}
