#ifndef LBLOCKGRAHPHICSITEM_H
#define LBLOCKGRAHPHICSITEM_H

#include <QGraphicsRectItem>
#include <QString>

/**
 * This class contains the items on the screen
 */
class LBlockGraphicsItem : public QGraphicsRectItem
{
	/// This stores the name of the item
	QString name;

    public:
	/// This sets the name of the item
	void setName(const QString &);

	/// This returns the name of the string
	const QString &getName();

	/// Constructor
	LBlockGraphicsItem(float, float, float, float, const QString &);
};

#endif
