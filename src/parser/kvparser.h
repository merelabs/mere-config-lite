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

    virtual std::vector<Property *> parse() const override;
    virtual Property* parse(const std::string &key) const override;

private:
    const Spec::Base &m_spec;
};

}
}
}

#endif // MERE_CONFIG_PARSER_KVPARSER_H
