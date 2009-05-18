#ifndef TEXTURESWINDOW_H
#define TEXTURESWINDOW_H

#include <QDialog>
#include <QStandardItemModel>
#include <QString>

#include "textureslist.h"
#include "lblockxmlengine.h"

namespace Ui {
	class TexturesWindow;
}

/// This is a dialog that holds the TexturesView
class TexturesWindow : public QDialog {
	Q_OBJECT

	/// This holds the UI Objects
	Ui::TexturesWindow *ui;

	/// The model with the textures
	TexturesList model;

	/// A Pointer to the XML Engine
	LBlockXmlEngine *doc;

    public:
	/// Constructor
	TexturesWindow(LBlockXmlEngine *doc, QWidget *parent = NULL);

	~TexturesWindow();

    public slots:
	
	/// This is called when we should edit a texture
	void slotEditTexture(QString);

	/// This is called when we should remove a texture
	void slotRemoveTexture(QString);

	/// This is called when we should create a new texture
	void slotNewTexture();

	/// Call this when we should refresh the view
	void refresh();

    signals:

	/// This signal is emitted when there has been some change to the textures.
	/// This is sent to the main window for signifying that we should save
	void dirty();
};

#endif
