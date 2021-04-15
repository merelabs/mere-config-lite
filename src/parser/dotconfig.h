#ifndef MERE_CONFIG_PARSER_DOTCONFIG_H
#define MERE_CONFIG_PARSER_DOTCONFIG_H

#include "propertyconfig.h"

namespace Mere
{
namespace Config
{
namespace Parser
{

class DotConfig : public PropertyConfig
{
public:
    DotConfig(const std::string &path);
};

}
}
}
#endif // MERE_CONFIG_PARSER_DOTCONFIG_H
