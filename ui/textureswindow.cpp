#include "textureswindow.h"

#include "ui_textureswindow.h"

TexturesWindow::TexturesWindow(QDomDocument *doc, QWidget *parent) : QDialog(parent), model(doc, this)
{
	ui = new Ui::TexturesWindow;
	ui->setupUi(this);

	ui->listView->setModel(&model);
	ui->listView->setViewMode(QListView::IconMode);
	ui->listView->setMovement(QListView::Static);
	ui->listView->setAcceptDrops(true);
}

TexturesWindow::~TexturesWindow()
{
	delete ui;
}

void TexturesWindow::refresh()
{
	model.parse();
}
