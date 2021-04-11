#ifndef MIXCONFIG_H
#define MIXCONFIG_H

#include "groupconfig.h"

namespace Mere
{
namespace Config
{
namespace Parser
{

class CrossConfig : public GroupConfig
{
public:
    CrossConfig(const std::string &path);

private:
    std::string m_delimiter;
    std::string m_group;
};

}
}
}

#endif // MIXCONFIG_H
