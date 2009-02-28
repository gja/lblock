#include "ui_edittexture.h"
#include "edittexture.h"

#include <qmath.h>

#include <QFileDialog>
#include <QBuffer>
#include <QDomElement>
#include <QColorDialog>
#include <QPalette>

ModifyTexture::ModifyTexture(QDomDocument *d, QWidget *parent) : QDialog(parent), doc(d)
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

EditTexture::EditTexture(QString n, QDomDocument *doc, QWidget *parent) : ModifyTexture(doc, parent)
{
	QDomElement root = doc->documentElement().toElement();
	QDomElement textures = root.elementsByTagName("textures").item(0).toElement();

	for (QDomNode i = textures.firstChild(); !i.isNull(); i = i.nextSibling())
	{
		QDomElement e = i.toElement();

		QString xmlname = e.attribute("name");

		if (xmlname == n) {
			name = xmlname;
			elem = e;
			value = e.attribute("value");
			color = e.attribute("color", "0xFFFFFF");
			xscale = e.attribute("xscale", "1.0");
			yscale = e.attribute("yscale", "1.0");
			
			break;
		}
	}

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

	elem.setAttribute("xscale", xscale);
	elem.setAttribute("yscale", yscale);
	elem.setAttribute("color", color);

	accept();
}

NewTexture::NewTexture(QDomDocument *doc, QWidget *parent) : ModifyTexture(doc, parent)
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


	QDomElement root = doc->documentElement().toElement();
	QDomElement textures = root.elementsByTagName("textures").item(0).toElement();

	QDomElement elem = doc->createElement("texture");
	textures.appendChild(elem);

	elem.setAttribute("name", name);
	elem.setAttribute("value", value);
	elem.setAttribute("xscale", xscale);
	elem.setAttribute("yscale", yscale);
	elem.setAttribute("color", color);

	accept();
}
