#ifndef LBLOCKVALUES_H
#define LBLOCKVALUES_H

#include <QHash>
#include <QDomElement>
#include <QList>

/// This class is the prefered way to send data between classes.
/// It is basically a hash in which you can set various properties
/// It may also hold a QDomElement if necessary
class LBlockValues : public QHash<QString, QString>
{
	/// This holds an element. This should not be accessed directly
	/// or at all, except via \ref writeToElement()
	QDomElement elem;

    public:
	/// A Blank Constructor
	LBlockValues() : QHash<QString, QString>(), elem()
	{}

	/// The Preferred Constructor
	LBlockValues(const QDomElement &e) : QHash<QString, QString>(), elem(e)
	{}

	/// Copy Constructor
	LBlockValues(const QHash<QString, QString> hash) : QHash<QString, QString>(hash), elem()
	{}

	/// Copy Constructor
	LBlockValues(const LBlockValues &other) : QHash<QString, QString>(other), elem(other.elem)
	{
	}

	LBlockValues operator=(const LBlockValues &other);

	/// Return the QDomElement. \warning Do not Use
	const QDomElement &element()
	{
		return elem;
	}

	/// This writes back to the element
	void writeToElement();
};

/// List of many LBlockValues
typedef QList<LBlockValues> LBlockValuesList;

#endif
