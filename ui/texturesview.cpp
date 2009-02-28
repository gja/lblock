#include "texturesview.h"

#include <QDebug>
#include <QMouseEvent>
#include <QKeyEvent>

TexturesView::TexturesView(QWidget *parent) : QListView(parent)
{

}

void TexturesView::mouseDoubleClickEvent(QMouseEvent *event)
{
	QModelIndexList list = selectedIndexes();

	if (! list.isEmpty())
		emit(editTexture(list[0].data().toString()));
}

void TexturesView::keyPressEvent(QKeyEvent *event)
{
	if (event->key() != Qt::Key_Return)
		return;

	QModelIndexList list = selectedIndexes();

	if (! list.isEmpty())
		emit(editTexture(list[0].data().toString()));
}
