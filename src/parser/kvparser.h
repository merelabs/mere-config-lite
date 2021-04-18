#ifndef MERE_CONFIG_PARSER_KVPARSER_H
#define MERE_CONFIG_PARSER_KVPARSER_H

#include "propertyparser.h"
#include "../spec/base.h"
#include "../property.h"

#include <string>

namespace Mere
{
namespace Config
{
namespace Parser
{

class MERE_CONFIG_LIB_SPEC KVParser : public PropertyParser
{
public:
    explicit KVParser(const Spec::Base &spec);

    virtual std::vector<Property *> parseProperties() const override;
    virtual Property* parseProperty(const std::string &key) const override;
};

}
}
}

#endif // MERE_CONFIG_PARSER_KVPARSER_H
