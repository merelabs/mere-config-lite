#ifndef PROPERTY_H
#define PROPERTY_H

#include "global.h"
#include <string>

namespace Mere
{
namespace Config
{

class MERE_CONFIG_LIB_SPEC Property
{
public:
    ~Property() = default;
    Property() = default;
    explicit Property(const std::string &name);
    explicit Property(const std::string &name, const std::string &value);

    Property(const Property &that) = default;
    Property& operator=(const Property &that) = default;

    Property(Property &&that) = default;
    Property& operator=(Property &&that) = default;

    std::string name() const;
    void name(const std::string &name);

    std::string value() const;
    void value(const std::string &value);

private:
    std::string m_name;
    std::string m_value;
};

}
}
#endif // PROPERTY_H
