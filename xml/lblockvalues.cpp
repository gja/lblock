#include "lblockvalues.h"

void LBlockValues::writeToElement()
{
	QHashIterator<QString, QString> i(*this);

	while (i.hasNext()) {
		i.next();
		elem.setAttribute(i.key(), i.value());
	}
}

LBlockValues LBlockValues::operator=(const LBlockValues &other)
{
	elem = other.elem;

	clear();
	foreach(QString key, other.keys())
		insert(key, other[key]);

	return *this;
}
