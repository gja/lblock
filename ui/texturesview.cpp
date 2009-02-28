#include "texturesview.h"

#include <QDebug>
#include <QMouseEvent>

TexturesView::TexturesView(QWidget *parent) : QListView(parent)
{

}

void TexturesView::mouseDoubleClickEvent(QMouseEvent *event)
{
	qDebug()<<indexAt(event->pos()).data().toString();
}
