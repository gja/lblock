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

	/// This ensures that the appropriate floors have been created
	/// \param lower The lowest floor
	/// \param upper The top most floor
	void ensureFloorsExist(int lower, int upper);

	/// This returns a list of all the textures
	LBlockValuesList getTexturesList();

	/// This adds a texture
	/// \param values The values of the Texture
	void addTexture(const LBlockValues &values);

	/// The gets a named texture
	/// \param name The name of the Texture
	LBlockValues getTexture(const QString &name);

	/// Remove the named texture
	/// \param name The name of the Texture
	void removeTexture(const QString &name);

	/// This adds a window to a wall
	/// \param values The Values of the Window
	void addWindowToWall(const LBlockValues &values);

	/// This deletes and item from the XML
	/// \param name The name of the Item
	void deleteItem(const QString &name);
};

#endif
