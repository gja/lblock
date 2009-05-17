#ifndef LBLOCKXMLENGINE
#define LBLOCKXMLENGINE

#include <QDomDocument>
#include <QHash>
#include <QList>
#include <QString>

#include "lblockvalues.h"

class LBlockXmlEngine : public QDomDocument
{
	/// The returns a node containing the current floor
	/// \param n The Floor to Get
	QDomNode getCurrentFloor(int n);

    public:
	/// This is the constructor
	/// \param name The name of the Document
	LBlockXmlEngine(const char *name);

	/// This returns current properties
	LBlockValues getProperties();

	/// This returns all items on a particular floor
	/// \param n The Floor to get items of
	LBlockValuesList getItemsOnFloor(int n);

	/// This returns on item on the floor by name
	/// \param n The Floor
	/// \param name The name of the Item
	LBlockValues getItemOnFloor(int n, const QString &name);

	/// This adds an Item to the Floor
	/// \param n The Floor
	/// \param hash A Hash containing the properties
	void addItemOnFloor(int n, const LBlockValues &hash);
};

#endif
