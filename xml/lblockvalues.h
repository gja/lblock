#ifndef LBLOCKVALUES_H
#define LBLOCKVALUES_H

#include <QHash>
#include <QDomElement>
#include <QList>

class LBlockValues : public QHash<QString, QString>
{
	QDomElement elem;

    public:
	LBlockValues() : QHash<QString, QString>(), elem()
	{}

	LBlockValues(const QDomElement &e) : QHash<QString, QString>(), elem(e)
	{}

	LBlockValues(const QHash<QString, QString> hash) : QHash<QString, QString>(hash), elem()
	{}

	LBlockValues(const LBlockValues &other) : QHash<QString, QString>(other), elem(other.elem)
	{
	}

	const QDomElement &element()
	{
		return elem;
	}

	/// This writes back to the element
	void writeToElement();
};

typedef QList<LBlockValues> LBlockValuesList;

#endif
