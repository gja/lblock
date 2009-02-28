#include "ui_edittexture.h"
#include "edittexture.h"

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

	if (newcolor.isValid())
		color = QString("0x") + QString::number(newcolor.rgb(), 16).toUpper();

	SetButtonColor(ui->colorButton, newcolor);
}

void ModifyTexture::slotChangeImage()
{
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
