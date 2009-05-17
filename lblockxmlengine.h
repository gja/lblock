#ifndef LBLOCKXMLENGINE
#define LBLOCKXMLENGINE

#include <QDomDocument>

class LBlockXmlEngine : public QDomDocument
{
    public:
	LBlockXmlEngine(const char *name);
};

#endif
