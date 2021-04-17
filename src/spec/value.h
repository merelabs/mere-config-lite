#ifndef MERE_CONFIG_PARSER_VALUECONFIG_H
#define MERE_CONFIG_PARSER_VALUECONFIG_H

#include "../global.h"
#include "domain.h"

namespace Mere
{
namespace Config
{
namespace Spec
{

class MERE_CONFIG_LIB_SPEC Value : public Domain
{
public:
    Value();
    explicit Value(const std::string &pattern);
    bool isValue(const std::string &line) const;
};

}
}
}
#endif // MERE_CONFIG_PARSER_VALUECONFIG_H
