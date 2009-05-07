#ifndef LBLOCKGRAHPHICSITEM_H
#define LBLOCKGRAHPHICSITEM_H

#include <QGraphicsRectItem>
#include <QString>

class LBlockGraphicsItem : public QGraphicsRectItem
{
	/// This stores the name of the item
	QString name;

    public:
	/// This sets the name of the item
	void setName(const QString &);

	/// This returns the name of the string
	QString getName();

	/// Constructor
	LBlockGraphicsItem(float, float, float, float, const QString &);
};

#endif
