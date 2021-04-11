#ifndef DOCUMENTCONFIG_H
#define DOCUMENTCONFIG_H

#include "groupconfig.h"

namespace Mere
{
namespace Config
{
namespace Parser
{

class MERE_CONFIG_LIB_SPEC DocumentConfig : public GroupConfig
{
public:
    DocumentConfig(const std::string &path);
};

}
}
}
#endif // DOCUMENTCONFIG_H
