#ifndef MERE_CONFIG_PROPERTY_H
#define MERE_CONFIG_PROPERTY_H

#include "global.h"
#include <string>

namespace Mere
{
namespace Config
{

class Group;

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

    bool valid() const;

    std::string path() const;
    void path(const std::string &path);

    Group* group() const;
    void group(Group *group);


private:
    std::string m_name;
    std::string m_value;

    std::string m_path;
    Group *m_group;
};

}
}
#endif // MERE_CONFIG_PROPERTY_H
