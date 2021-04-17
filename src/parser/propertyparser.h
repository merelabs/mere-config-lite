#ifndef MERE_CONFIG_PARSER_PROPERTYPARSER_H
#define MERE_CONFIG_PARSER_PROPERTYPARSER_H

#include "parser.h"
#include "../spec/base.h"
#include "../property.h"

namespace Mere
{
namespace Config
{

namespace Parser
{

class MERE_CONFIG_LIB_SPEC PropertyParser : public Parser
{
public:
    explicit PropertyParser(const Spec::Base &spec);

    virtual std::vector<Property *> parse() const = 0;
    virtual Property* parse(const std::string &key) const = 0;

protected:
    // move to next valid property
    bool next(std::ifstream &file, std::string &line) const;
};

}
}
}

#endif // MERE_CONFIG_PARSER_PROPERTYPARSER_H
