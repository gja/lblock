#include "textureswindow.h"

#include "ui_textureswindow.h"

TexturesWindow::TexturesWindow(QWidget *parent) : QDialog(parent), model(this)
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
