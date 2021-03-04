#ifndef MERE_CONFIG_PATHRESOLVER_H
#define MERE_CONFIG_PATHRESOLVER_H

#include "global.h"

namespace Mere
{
namespace Config
{

class MERE_CONFIG_LIB_SPEC PathResolver
{
public:
    PathResolver() = default;
    std::string resolve(const std::string &path, const std::string &type);
};

}
}

#endif // MERE_CONFIG_PATHRESOLVER_H
