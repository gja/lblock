#ifndef ITEMPROPERTIES_H
#define ITEMPROPERTIES_H

#include <QDialog>
#include "itempropertiesmodel.h"
#include "lblockvalues.h"

namespace Ui {
	class ItemPropertiesDialog;
}

/**
 * This class contains the properties of the items.
 * It pops a dialog box which contains the properties of the item being selected
 */
class ItemPropertiesDialog : public QDialog {
	Q_OBJECT
	
	/// This holds all the ui related objects
	Ui::ItemPropertiesDialog *ui;
	
	/// This is a model class. It contains all the properties of the element
	ItemPropertiesModel *model;
	
	///  The current values of the properties.
	LBlockValues elem;

    public:
    	/// This function pops up the properties dialog
	ItemPropertiesDialog(QWidget *parent = NULL);

	~ItemPropertiesDialog();
	

    public slots:
    	/// Sets the values of the item being selected
	void setItem(const LBlockValues &e);
	/// It changes the attribute of the item selected
	void slotModifyAttribute(const QString &);
	
    signals:
    	/// Its emitted when something is changed
	void dirty();
};

#endif
