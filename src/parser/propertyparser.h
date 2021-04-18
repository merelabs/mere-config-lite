#ifndef MERE_CONFIG_PARSER_PROPERTYPARSER_H
#define MERE_CONFIG_PARSER_PROPERTYPARSER_H

#include "lineparser.h"
#include "../spec/base.h"
#include "../property.h"

namespace Mere
{
namespace Config
{

namespace Parser
{

class MERE_CONFIG_LIB_SPEC PropertyParser : public LineParser
{
public:
    explicit PropertyParser(const Spec::Base &spec);

    virtual std::vector<Property *> parseProperties() const = 0;
    virtual Property* parseProperty(const std::string &key) const = 0;

protected:
    // move to next valid property
    bool next(std::ifstream &file, std::string &line) const;

//    // it shoild not know about key/value
//    std::string key(const std::string &line) const;
//    std::string value(const std::string &line) const;
};

}
}
}

#endif // MERE_CONFIG_PARSER_PROPERTYPARSER_H
