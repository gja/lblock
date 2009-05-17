#ifndef EDITTEXTURES_H
#define EDITTEXTURES_H

#include <QDialog>
#include <QString>

#include "lblockxmlengine.h"

namespace Ui {
	class EditTexture;
}

class ModifyTexture : public QDialog
{
	Q_OBJECT

    protected:

	Ui::EditTexture *ui;
	
	/// The value of the image stored in base64
	QString value;

	/// The value of the backup color in Hexadecimal
	QString color;

	/// The name of the texture
	QString name;

	/// The x scale of the texture
	QString xscale;

	/// The y scale of the texture
	QString yscale;

	/// The XML Document containing the textures
	LBlockXmlEngine *doc;

    public:

	ModifyTexture(LBlockXmlEngine *doc, QWidget *parent = NULL);

	virtual ~ModifyTexture();

    public slots:

	virtual void slotVerifyAndAccept() = 0;

	void slotChangeColor();

	void slotChangeImage();

    signals:

	void error(QString);
};

class EditTexture : public ModifyTexture
{
	Q_OBJECT

	LBlockValues elem;

    public:
	EditTexture(QString name, LBlockXmlEngine *doc, QWidget *parent = NULL);

    public slots:

	void slotVerifyAndAccept();
};

class NewTexture : public ModifyTexture
{
	Q_OBJECT

    public:

	NewTexture(LBlockXmlEngine *doc, QWidget *parent = NULL);

    public slots:

	void slotVerifyAndAccept();
};

#endif
