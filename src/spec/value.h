#ifndef MERE_CONFIG_PARSER_VALUE_H
#define MERE_CONFIG_PARSER_VALUE_H

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
    virtual ~Value();
    Value();

    Value(const Value &that) = default;
    Value& operator=(const Value &that) = default;
    Value(Value &&that) = default;
    Value& operator=(Value &&that) = default;

    explicit Value(const std::string &pattern);
    bool isValue(const std::string &line) const;
};

}
}
}
#endif // MERE_CONFIG_PARSER_VALUE_H
