#ifndef PROPERTIES_H
#define PROPERTIES_H

#include <QDialog>


namespace Ui {
	class PropertiesDialog;
}
class LBlockXmlEngine;

class PropertiesDialog : public QDialog {
	Q_OBJECT

	Ui::PropertiesDialog *ui;

	LBlockXmlEngine *doc;

    public:
	PropertiesDialog(LBlockXmlEngine *doc, QWidget *parent = NULL);

	~PropertiesDialog();
	

    public slots:
	void slotVerifyAndAccept();
	
    signals:
};

#endif
