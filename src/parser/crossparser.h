#ifndef MERE_CONFIG_PARSER_CROSSPARSER_H
#define MERE_CONFIG_PARSER_CROSSPARSER_H

#include "../property.h"
#include "../group.h"
#include "propertyparser.h"
#include "../spec/baseex.h"

namespace Mere
{
namespace Config
{
namespace Parser
{

class MERE_CONFIG_LIB_SPEC CrossParser : public LineParser
{
public:
    explicit CrossParser(const Spec::BaseEx &spec);

    virtual Group* parse() const = 0;

    virtual std::vector<Mere::Config::Property *> properties() const = 0;
    virtual std::vector<Mere::Config::Group *> groups() const = 0;

    virtual Group* parse(const std::string &name) const = 0;
    virtual Property* parse(const std::string &name, const std::string &key) const = 0;
};

}
}
}

#endif // MERE_CONFIG_PARSER_CROSSPARSER_H
