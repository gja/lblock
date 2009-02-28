#ifndef TEXTURESLIST_H
#define TEXTURESLIST_H

#include <QStandardItemModel>
#include <QList>
#include <QStandardItem>

class QDomDocument;

class TexturesList : public QStandardItemModel
{
	/// This is the XML Document
	QDomDocument *doc;

	/// This has a list of all the items (if we need to delete)
	QList<QStandardItem *> items;

	/// This function deletes all items
	void clear();

    public:
	TexturesList(QDomDocument *doc, QObject *parent = NULL);

	/**
	 * This clears the list, parses the document
	 * and then repopulates the list
	 */
	void parse();
};

#endif
