#ifndef PROPERTIES_H
#define PROPERTIES_H

#include <QDialog>

namespace Ui {
	class PropertiesDialog;
}
class QDomDocument;

class PropertiesDialog : public QDialog {
	Q_OBJECT

	Ui::PropertiesDialog *ui;

	QDomDocument *doc;

    public:
	PropertiesDialog(QDomDocument *doc, QWidget *parent = NULL);

	~PropertiesDialog();

    public slots:
	void slotVerifyAndAccept();
	
    signals:
};

#endif
