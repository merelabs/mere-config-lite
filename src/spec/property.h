#ifndef MERE_CONFIG_SPEC_PROPERTY_H
#define MERE_CONFIG_SPEC_PROPERTY_H

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
    virtual ~Property();
    Property();
    Property(const std::string &pattern);

    Property(const Property &that)
        : Domain(that),
          m_delimiter(that.m_delimiter),
          m_key(that.m_key ? new Key(*that.m_key) : nullptr),
          m_value(that.m_value ? new Value(*that.m_value) : nullptr)
    {
    };

    Property& operator=(const Property &that)
    {
        Domain::operator=(that);

        Property copy{that};
        swap(*this, copy);

        return *this;
    };

    Property(Property &&that) = default;
    Property& operator=(Property &&that) = default;

    friend void swap(Property &lhs, Property &rhs)
    {
        using std::swap;
        swap(static_cast<Domain&>(lhs), static_cast<Domain&>(rhs));
        swap(lhs.m_delimiter  , rhs.m_delimiter);
        swap(lhs.m_key        , rhs.m_key);
        swap(lhs.m_value      , rhs.m_value);
    }

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

#endif // MERE_CONFIG_SPEC_PROPERTY_H
