#ifndef MERE_CONFIG_PARSER_KVPARSER_H
#define MERE_CONFIG_PARSER_KVPARSER_H

#include "propertyparser.h"
#include "propertyconfig.h"
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
    explicit KVParser(const PropertyConfig &config);

    virtual std::vector<Property *> parse() const override;
    virtual Property* parse(const std::string &key) const override;

private:
    const PropertyConfig &m_config;
};

}
}
}

#endif // MERE_CONFIG_PARSER_KVPARSER_H
