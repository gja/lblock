#include "ui_edittexture.h"
#include "edittexture.h"

#include <QDomElement>

ModifyTexture::ModifyTexture(QDomDocument *d, QWidget *parent) : QDialog(parent), doc(d)
{
	ui = new Ui::EditTexture();
	ui->setupUi(this);
}

ModifyTexture::~ModifyTexture()
{
	delete ui;
}

void ModifyTexture::slotChangeColor()
{
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
}

void EditTexture::slotVerifyAndAccept()
{
	xscale = QString::number(ui->xscale->value());
	yscale = QString::number(ui->yscale->value());

	elem.setAttribute("xscale", xscale);
	elem.setAttribute("yscale", yscale);

	accept();
}
