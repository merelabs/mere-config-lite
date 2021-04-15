#ifndef MERE_CONFIG_PARSER_VALUECONFIG_H
#define MERE_CONFIG_PARSER_VALUECONFIG_H

#include <string>

namespace Mere
{
namespace Config
{
namespace Parser
{

class ValueConfig
{
public:
    ValueConfig();
    std::string pattern() const;
    void pattern(const std::string &pattern);

private:
    std::string m_pattern;
};

}
}
}
#endif // MERE_CONFIG_PARSER_VALUECONFIG_H
