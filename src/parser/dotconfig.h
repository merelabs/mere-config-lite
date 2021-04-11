#ifndef DOTCONFIG_H
#define DOTCONFIG_H

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
#endif // DOTCONFIG_H
