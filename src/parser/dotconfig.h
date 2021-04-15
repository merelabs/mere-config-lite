#ifndef MERE_CONFIG_PARSER_DOTCONFIG_H
#define MERE_CONFIG_PARSER_DOTCONFIG_H

#include "config.h"

namespace Mere
{
namespace Config
{
namespace Parser
{

class DotConfig : public Config
{
public:
    DotConfig(const std::string &path);
};

}
}
}
#endif // MERE_CONFIG_PARSER_DOTCONFIG_H
