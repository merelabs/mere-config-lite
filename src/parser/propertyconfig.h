#ifndef MERE_CONFIG_PARSER_PROPERTYCONFIG_H
#define MERE_CONFIG_PARSER_PROPERTYCONFIG_H

#include "config.h"

namespace Mere
{
namespace Config
{

namespace Parser
{

class MERE_CONFIG_LIB_SPEC PropertyConfig : public Config
{
public:
    PropertyConfig(const std::string &path);

    std::string delimiter() const;
    void delimiter(const std::string &delimiter);

    std::string property() const;
    void property(const std::string &property);
    bool isProperty(const std::string &line) const;

private:
    std::string m_delimiter;
    std::string m_property;
};

}
}
}

#endif // MERE_CONFIG_PARSER_PROPERTYCONFIG_H
