#ifndef ITEMPROPERTIES_H
#define ITEMPROPERTIES_H

#include <QDialog>


namespace Ui {
	class ItemPropertiesDialog;
}

class ItemPropertiesDialog : public QDialog {
	Q_OBJECT

	Ui::ItemPropertiesDialog *ui;

    public:
	ItemPropertiesDialog(QWidget *parent = NULL);

	~ItemPropertiesDialog();
	

    public slots:
	
    signals:
};

#endif
