#ifndef MERE_CONFIG_PARSER_GROUPCONFIG_H
#define MERE_CONFIG_PARSER_GROUPCONFIG_H

#include "../global.h"

namespace Mere
{
namespace Config
{
namespace Parser
{

class MERE_CONFIG_LIB_SPEC GroupConfig
{
public:
    GroupConfig();
    GroupConfig(const std::string &pattern);

    std::string delimiter() const;
    void delimiter(const std::string &delimiter);

    std::string pattern() const;
    void pattern(const std::string &pattern);

    bool isGroup(const std::string &line) const;
    bool isSubGroup(const std::string &line) const;

    std::string name(const std::string &line) const;
    std::string subgroup(const std::string &group) const;
    std::string parent(const std::string &group) const;
    std::string base(const std::string &group) const;

private:
    std::string m_delimiter;
    std::string m_pattern;

    std::string m_subgroup;

};

}
}
}

#endif // MERE_CONFIG_PARSER_GROUPCONFIG_H
