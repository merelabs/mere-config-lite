#ifndef MERE_CONFIG_PARSER_KEYCONFIG_H
#define MERE_CONFIG_PARSER_KEYCONFIG_H

#include <string>

namespace Mere
{
namespace Config
{
namespace Parser
{

class KeyConfig
{
public:
    KeyConfig();
    explicit KeyConfig(const std::string &pattern);

    std::string pattern() const;
    void pattern(const std::string &pattern);

private:
    std::string m_pattern;
};

}
}
}

#endif // MERE_CONFIG_PARSER_KEYCONFIG_H
