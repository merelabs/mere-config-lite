#ifndef MERE_CONFIG_PARSER_EXCONFIG_H
#define MERE_CONFIG_PARSER_EXCONFIG_H

#include "config.h"
#include "groupconfig.h"

namespace Mere
{
namespace Config
{
namespace Parser
{

class MERE_CONFIG_LIB_SPEC ConfigEx : public Config
{
public:
    ConfigEx(const std::string &path);

    GroupConfig group() const;
    void group(const GroupConfig &group);
    bool isGroup(const std::string &line) const;

private:
  GroupConfig m_group;
};

}
}
}
#endif // MERE_CONFIG_PARSER_EXCONFIG_H
