#include "lblockvalues.h"

void LBlockValues::writeToElement()
{
	QHashIterator<QString, QString> i(*this);

	while (i.hasNext()) {
		i.next();
		elem.setAttribute(i.key(), i.value());
	}
}
