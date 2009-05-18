#ifndef PROPERTIES_H
#define PROPERTIES_H

#include <QDialog>


namespace Ui {
	class PropertiesDialog;
}
class LBlockXmlEngine;

/// This is a dialog for properties of the floor plan.
/// This is accessed via Design->Properties
class PropertiesDialog : public QDialog {
	Q_OBJECT

	/// This holds the UI object
	Ui::PropertiesDialog *ui;

	/// A Pointer to the XML engine
	LBlockXmlEngine *doc;

    public:
	/// Constructor
	PropertiesDialog(LBlockXmlEngine *doc, QWidget *parent = NULL);

	~PropertiesDialog();
	

    public slots:
	/// This verifies the data, and saves
	void slotVerifyAndAccept();
	
    signals:
};

#endif
