#ifndef DOCUMENTCONFIG_H
#define DOCUMENTCONFIG_H

#include "configex.h"

namespace Mere
{
namespace Config
{
namespace Parser
{

class MERE_CONFIG_LIB_SPEC DocumentConfig : public ConfigEx
{
public:
    DocumentConfig(const std::string &path);
};

}
}
}
#endif // DOCUMENTCONFIG_H
