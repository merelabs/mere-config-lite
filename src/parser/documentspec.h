#ifndef DOCUMENTCONFIG_H
#define DOCUMENTCONFIG_H

#include "../spec/baseex.h"

namespace Mere
{
namespace Config
{
namespace Parser
{

class MERE_CONFIG_LIB_SPEC DocumentSpec : public Spec::BaseEx
{
public:
    DocumentSpec(const std::string &path);
};

}
}
}
#endif // DOCUMENTCONFIG_H
