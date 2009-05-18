#ifndef EDITTEXTURES_H
#define EDITTEXTURES_H

#include <QDialog>
#include <QString>

#include "lblockxmlengine.h"

namespace Ui {
	class EditTexture;
}

/**
 * This class can be used to load the textures of our choice.
 * It can be used to pop a dialog for loading the textures. The texture files
 * are of the extension png, bmp and jpeg.
 */

class ModifyTexture : public QDialog
{
	Q_OBJECT

    protected:

	/// This hold the UI objects
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

	/// Constructor
	ModifyTexture(LBlockXmlEngine *doc, QWidget *parent = NULL);

	/// Destructor
	virtual ~ModifyTexture();

    public slots:
	
	/// This slot is called when all the values are entered and needto be accepted and verified
	virtual void slotVerifyAndAccept() = 0;
	
	/// This slot is called when the colour is changed 
	void slotChangeColor();
	
	/// This slot is called when the image is changed
	void slotChangeImage();

    signals:
	/// This signal is emitted when there is a error
	void error(QString);
};

/// This class is to modify a Texture
class EditTexture : public ModifyTexture
{
	Q_OBJECT

	/// The XML Element that represents this texture
	LBlockValues elem;

    public:
	EditTexture(QString name, LBlockXmlEngine *doc, QWidget *parent = NULL);

    public slots:

	void slotVerifyAndAccept();
};

/// This class is to add a new texture
class NewTexture : public ModifyTexture
{
	Q_OBJECT

    public:

	NewTexture(LBlockXmlEngine *doc, QWidget *parent = NULL);

    public slots:

	void slotVerifyAndAccept();
};

#endif
