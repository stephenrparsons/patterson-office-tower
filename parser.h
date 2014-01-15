#ifndef _parser_included_
#define _parser_included_

#include <vector>
#include <map>
#include <functional>

#include "XMLSerializable.h"

void parseXML(std::map<std::string, std::function<XMLSerializable * ()>> & mConstructors, std::string sFilename, std::vector<XMLSerializable*> & vWorld);

#endif
