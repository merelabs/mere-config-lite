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

    Group(Group &&that) = default;
    Group& operator=(Group &&that) = default;

    std::string path() const;
    void path(const std::string &base);

    std::string name() const;
    void name(const std::string &name);

    std::vector<std::string> keys() const;
    std::vector<std::string> keys(int depth) const;

    Property *property(const std::string &name) const;
    void property(Property *property);

    std::vector<Property *> properties() const;
    std::vector<Property *> properties(int depth) const;

    void properties(const std::vector<Property *> &properties);

    std::vector<Group *> groups() const;
    std::vector<Group *> groups(int depth) const;

    Group* group(const std::string &name) const;

    void group(Group *group);
    void groups(const std::vector<Group *> &groups);

    virtual bool valid() const;
    void dump() const;

    Group* parent() const;
    void parent(Group *parent);


private:
    std::string             m_name;
    std::vector<Property *> m_properties;
    std::vector<Group *>    m_groups;

    std::string             m_path;
    Group*                  m_parent;
};

}
}
#endif // MERE_CONFIG_GROUP_H
