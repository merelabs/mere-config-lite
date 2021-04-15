#ifndef MERE_CONFIG_PARSER_PROPERTYCONFIG_H
#define MERE_CONFIG_PARSER_PROPERTYCONFIG_H

#include "../global.h"
#include "keyconfig.h"
#include "valueconfig.h"

namespace Mere
{
namespace Config
{

namespace Parser
{

class MERE_CONFIG_LIB_SPEC PropertyConfig
{
public:
    PropertyConfig();
    PropertyConfig(const std::string &pattern);

    std::string delimiter() const;
    void delimiter(const std::string &delimiter);

    std::string pattern() const;
    void pattern(const std::string &property);
    bool isProperty(const std::string &line) const;

private:
    std::string m_delimiter;
    std::string m_pattern;

    KeyConfig m_key;
    ValueConfig m_value;
};

}
}
}

#endif // MERE_CONFIG_PARSER_PROPERTYCONFIG_H
