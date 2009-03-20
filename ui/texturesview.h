#ifndef TEXTURESVIEW_H
#define TEXTURESVIEW_H

#include <QListView>

class TexturesView : public QListView {

	Q_OBJECT

    public:
	TexturesView(QWidget *parent = NULL);

	void mouseDoubleClickEvent(QMouseEvent *event);

	void keyPressEvent(QKeyEvent *event);

	void mouseReleaseEvent(QMouseEvent *event);

    public slots:

	void slotEditSelected();

	void slotDeleteSelected();

	void slotNewTexture();

    signals:
	void editTexture(QString);

	void deleteTexture(QString);

	void newTexture();
};

#endif
