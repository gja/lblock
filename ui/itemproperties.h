#ifndef ITEMPROPERTIES_H
#define ITEMPROPERTIES_H

#include <QDialog>
#include "itempropertiesmodel.h"
#include "lblockvalues.h"

namespace Ui {
	class ItemPropertiesDialog;
}

class ItemPropertiesDialog : public QDialog {
	Q_OBJECT

	Ui::ItemPropertiesDialog *ui;

	ItemPropertiesModel *model;

	LBlockValues elem;

    public:
	ItemPropertiesDialog(QWidget *parent = NULL);

	~ItemPropertiesDialog();
	

    public slots:
	void setItem(const LBlockValues &e);

	void slotModifyAttribute(const QString &);
	
    signals:
	void dirty();
};

#endif
