#ifndef TEXTURESVIEW_H
#define TEXTURESVIEW_H

#include <QListView>

/// This is the View that shows the various textures.
/// It is using the Qt Model/View Framework
class TexturesView : public QListView {

	Q_OBJECT

    public:
	TexturesView(QWidget *parent = NULL);

	/// This function is called when the mouse is double clicked.
	/// It brings up the edit texture window
	/// \param event The Mouse Event
	void mouseDoubleClickEvent(QMouseEvent *event);

	/// This is called when a key is pressed
	/// \param event The Mouse Event
	void keyPressEvent(QKeyEvent *event);

	/// This is called when we release the mouse
	/// \param event The Mouse Event
	void mouseReleaseEvent(QMouseEvent *event);

    public slots:

	/// This is called to edit the selected texture
	void slotEditSelected();

	/// This is called to delete the selected texture
	void slotDeleteSelected();

	/// This is called to create a new texture
	void slotNewTexture();

    signals:
	/// This is called to show that a texture should be edited
	void editTexture(QString);

	/// This is called to show that a texture should be deleted
	void deleteTexture(QString);

	/// This is called to show that a texture should be created
	void newTexture();
};

#endif
