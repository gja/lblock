#include "textureswindow.h"
#include "ui_textureswindow.h"
#include "edittexture.h"

#include <QMessageBox>

TexturesWindow::TexturesWindow(QDomDocument *d, QWidget *parent) : QDialog(parent), model(d, this), doc(d)
{
	ui = new Ui::TexturesWindow;
	ui->setupUi(this);

	connect(ui->listView, SIGNAL(editTexture(QString)), this, SLOT(slotEditTexture(QString)));
	connect(ui->listView, SIGNAL(deleteTexture(QString)), this, SLOT(slotRemoveTexture(QString)));
	connect(ui->listView, SIGNAL(newTexture()), this, SLOT(slotNewTexture()));

	ui->listView->setModel(&model);
	ui->listView->setViewMode(QListView::IconMode);
	ui->listView->setMovement(QListView::Static);
	ui->listView->setAcceptDrops(true);

	connect(this, SIGNAL(dirty()), parent, SLOT(slotMakeDirty()));
}

TexturesWindow::~TexturesWindow()
{
	delete ui;
}

void TexturesWindow::refresh()
{
	model.parse();
}

void TexturesWindow::slotEditTexture(QString item)
{
	EditTexture *edit = new EditTexture(item, doc, this);
	connect(edit, SIGNAL(accepted()), parent(), SLOT(slotMakeDirty()));
	edit->show();
}

void TexturesWindow::slotNewTexture()
{
	NewTexture *edit = new NewTexture(doc, this);
	connect(edit, SIGNAL(accepted()), parent(), SLOT(slotMakeDirty()));
	connect(edit, SIGNAL(accepted()), this, SLOT(refresh()));
	edit->show();
}

void TexturesWindow::slotRemoveTexture(QString item)
{
	QMessageBox::StandardButton response = QMessageBox::warning(this, "Delete Texture", QString("You are About to Permanently Delete Texture ") + item + "\nAre you sure that you want to Continue?", QMessageBox::Ok | QMessageBox::Cancel);

	if (response != QMessageBox::Ok)
		return;

	QDomElement root = doc->documentElement().toElement();
	QDomElement textures = root.elementsByTagName("textures").item(0).toElement();

	for (QDomNode i = textures.firstChild(); !i.isNull(); i = i.nextSibling())
	{
		QDomElement e = i.toElement();

		QString xmlname = e.attribute("name");

		if (xmlname == item) {
			textures.removeChild(i);
			refresh();
			emit(dirty());
			return;
		}
	}
}
