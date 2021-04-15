#include "group.h"

#include <iostream>

Mere::Config::Group::Group(const std::string &name)
    : m_name(name)
{

}

std::string Mere::Config::Group::name() const
{
    return m_name;
}

void Mere::Config::Group::name(const std::string &name)
{
    m_name = name;
}

Mere::Config::Property* Mere::Config::Group::property(const std::string &name) const
{
    if (name.empty()) return nullptr;

    auto it = std::find_if(m_properties.cbegin(), m_properties.cend(), [&](const Property *property){
        return property->name().compare(name) == 0;
    });

    if (it == m_properties.end()) return nullptr;

    return *it;
}

void Mere::Config::Group::property(Property *property)
{
    m_properties.push_back(property);
}

std::vector<Mere::Config::Property *> Mere::Config::Group::properties() const
{
    return m_properties;
}

std::vector<Mere::Config::Property *> Mere::Config::Group::properties(int depth) const
{
    std::vector<Mere::Config::Property *> properties = this->properties();

    for(const Group *group : groups())
    {
        std::vector<Mere::Config::Property *> _properties = group->properties(100);
        properties.insert(properties.end(), _properties.begin(), _properties.end());
    }

    return properties;
}

void Mere::Config::Group::properties(const std::vector<Property *> &properties)
{
    m_properties.clear();
    m_properties.insert(m_properties.end(), properties.begin(), properties.end());
}

std::vector<Mere::Config::Group *> Mere::Config::Group::groups() const
{
    return m_groups;
}

std::vector<Mere::Config::Group *> Mere::Config::Group::groups(int depth) const
{
    std::vector<Mere::Config::Group *> groups = this->groups();
    for(Group *group : m_groups)
    {
        std::vector<Mere::Config::Group *> _groups = group->groups();
        groups.insert(groups.end(), _groups.begin(), _groups.end());
    }

    return groups;
}

void Mere::Config::Group::group(Group *group)
{
    m_groups.push_back(group);
}

void Mere::Config::Group::groups(const std::vector<Group *> &groups)
{
    m_groups.clear();
    m_groups.insert(m_groups.end(), groups.begin(), groups.end());
}

std::string Mere::Config::Group::path() const
{
    return m_path;
}

void Mere::Config::Group::path(const std::string &base)
{
    m_path = base;
}

std::vector<std::string> Mere::Config::Group::keys() const
{
    std::vector<std::string> keys;

    for(const Property* property : m_properties)
        keys.push_back(property->name());

    return keys;
}

// FIXME - depth...
std::vector<std::string> Mere::Config::Group::keys(int depth) const
{
    std::vector<std::string> keys = this->keys();
    for(auto &key : keys)
    {
        if (!m_name.empty())
            key = key.insert(0, m_name + "/");

        if (!m_path.empty())
            key = key.insert(0, m_path + "/");
    }

    for(const Group *group : groups())
    {
        std::vector<std::string> _keys = group->keys(100);
        keys.insert(keys.end(), _keys.begin(), _keys.end());
    }

    return keys;
}

Mere::Config::Group* Mere::Config::Group::group(const std::string &name) const
{
    if (name.empty()) return nullptr;

    auto it = std::find_if(m_groups.cbegin(), m_groups.cend(), [&](const Group *group){
        return group->name().compare(name) == 0;
    });

    if (it == m_groups.cend())
        return nullptr;

    return *it;
}

Mere::Config::Group* Mere::Config::Group::parent() const
{
    return m_parent;
}

void Mere::Config::Group::parent(Group *parent)
{
    m_parent = parent;
}

bool Mere::Config::Group::valid() const
{
    return !m_name.empty();
}

void Mere::Config::Group::dump() const
{
    std::cout << "Group::" << name() << std::endl;
    std::cout << "Properties---------" << properties().size() << std::endl;
    for(const auto *property : properties())
        std::cout << "Property::" << property->name() << " => " << property->value() << std::endl;

    std::cout << "Subgroups---------" << groups().size() << std::endl;
    for(const auto *subgroup : groups())
        subgroup->dump();
}
