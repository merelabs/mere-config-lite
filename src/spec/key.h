#ifndef MERE_CONFIG_PARSER_KEYCONFIG_H
#define MERE_CONFIG_PARSER_KEYCONFIG_H

#include "../global.h"
#include "domain.h"

namespace Mere
{
namespace Config
{
namespace Spec
{

class MERE_CONFIG_LIB_SPEC Key : public Domain
{
public:
    Key();
    explicit Key(const std::string &pattern);

    bool isKey(const std::string &line) const;
};

}
}
}

#endif // MERE_CONFIG_PARSER_KEYCONFIG_H
