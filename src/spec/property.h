#ifndef MERE_CONFIG_PARSER_PROPERTYCONFIG_H
#define MERE_CONFIG_PARSER_PROPERTYCONFIG_H

#include "../global.h"
#include "domain.h"
#include "key.h"
#include "value.h"

namespace Mere
{
namespace Config
{

namespace Spec
{

class MERE_CONFIG_LIB_SPEC Property : public Domain
{
public:
    Property();
    Property(const std::string &pattern);

    std::string delimiter() const;
    void delimiter(const std::string &delimiter);

    bool isProperty(const std::string &line) const;

    Key* key() const;
    void key(Key *key);
    bool isKey(const std::string &line) const;

    Value* value() const;
    void value(Value *value);
    bool isValue(const std::string &line) const;

private:
    std::string m_delimiter;

    Key *m_key;
    Value *m_value;
};

}
}
}

#endif // MERE_CONFIG_PARSER_PROPERTYCONFIG_H
