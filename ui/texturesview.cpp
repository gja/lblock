#include "texturesview.h"

#include <QMouseEvent>
#include <QKeyEvent>
#include <QMenu>

TexturesView::TexturesView(QWidget *parent) : QListView(parent)
{

}

void TexturesView::mouseDoubleClickEvent(QMouseEvent *event)
{
	slotEditSelected();
}

void TexturesView::keyPressEvent(QKeyEvent *event)
{
	if (event->key() != Qt::Key_Return)
		return;

	slotEditSelected();
}

void TexturesView::slotEditSelected()
{
	QModelIndexList list = selectedIndexes();

	if (! list.isEmpty())
		emit(editTexture(list[0].data().toString()));
}

void TexturesView::slotDeleteSelected()
{
	QModelIndexList list = selectedIndexes();

	if (! list.isEmpty())
		emit(deleteTexture(list[0].data().toString()));
}

void TexturesView::slotNewTexture()
{
	emit(newTexture());
}

void TexturesView::mouseReleaseEvent(QMouseEvent *event)
{
	if (event->button() != Qt::RightButton)
		return;

	QMenu menu;
	menu.addAction(QIcon(":/icons/icons/list-add.png"), "Add Texture", this, SLOT(slotNewTexture()));

	if (! selectedIndexes().isEmpty()) {
		menu.addAction(QIcon(":/icons/icons/view-refresh.png"), "Edit Texture", this, SLOT(slotEditSelected()));
		menu.addAction(QIcon(":/icons/icons/list-remove.png"), "Remove Texture", this, SLOT(slotDeleteSelected()));
	}

	menu.exec(mapToGlobal(event->pos()));
}
