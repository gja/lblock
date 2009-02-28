#include "texturesview.h"

#include <QDebug>
#include <QMouseEvent>

TexturesView::TexturesView(QWidget *parent) : QListView(parent)
{

}

void TexturesView::mouseDoubleClickEvent(QMouseEvent *event)
{
	QString item = indexAt(event->pos()).data().toString();

	if (! item.isEmpty())
		emit(editTexture(item));
}
