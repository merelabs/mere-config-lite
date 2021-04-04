#ifndef MERE_CONFIG_GROUP_H
#define MERE_CONFIG_GROUP_H

#include "global.h"
#include "property.h"

#include <vector>

namespace Mere
{
namespace Config
{

class MERE_CONFIG_LIB_SPEC Group
{
public:
    ~Group() = default;
    Group() = default;
    explicit Group(const std::string &name);

    Group(const Group &that) = default;
    Group& operator=(const Group &that) = default;

    Group(Group &&thst) = default;
    Group& operator=(Group &&that) = default;

    std::string name() const;
    void name(const std::string &name);

    Property property(const std::string &name, int *set = nullptr);
    void property(const Property &property);

    std::vector<Property> properties() const;
    void properties(const std::vector<Property> &properties);

    std::vector<Group> groups() const;
    void group(const Group &group);
    void groups(const std::vector<Group> &groups);

    bool valid() const;

private:
    std::string           m_name;
    std::vector<Property> m_properties;
    std::vector<Group>    m_subgroups;
};

}
}
#endif // MERE_CONFIG_GROUP_H
