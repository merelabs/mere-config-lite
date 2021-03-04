#ifndef MERE_CONFIG_HOMESPEC_H
#define MERE_CONFIG_HOMESPEC_H

#include "global.h"

namespace Mere
{
namespace Config
{

class MERE_CONFIG_LIB_SPEC HomeSpec
{
private:
    HomeSpec() = default;

public:
    static std::string  local();
    static std::string  system();
    static std::vector<std::string> homes();
};

}
}

#endif // MERE_CONFIG_HOMESPEC_H
