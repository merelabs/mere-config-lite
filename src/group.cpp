#include "group.h"

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

Mere::Config::Property Mere::Config::Group::property(const std::string &name, int *set)
{
//    auto pos = std::find(m_properties.begin(), m_properties.end(), [&](Property &property) -> bool{
//        return property.name().compare(name) == 0;
//    });

//    if (pos == m_properties.end())
//    {
//        if (set) *set = 0;
//        return Property();
//    }

//    if (set) *set = 1;

//    return *pos;
}

void Mere::Config::Group::property(const Property &property)
{
    m_properties.push_back(property);
}

std::vector<Mere::Config::Property> Mere::Config::Group::properties() const
{
    return m_properties;
}

void Mere::Config::Group::properties(const std::vector<Property> &properties)
{
    m_properties.clear();
    m_properties.insert(m_properties.end(), properties.begin(), properties.end());
}

std::vector<Mere::Config::Group> Mere::Config::Group::groups() const
{
    return m_subgroups;
}

void Mere::Config::Group::group(const Group &group)
{
    m_subgroups.push_back(group);
}

void Mere::Config::Group::groups(const std::vector<Group> &groups)
{
    m_subgroups.clear();
    m_subgroups.insert(m_subgroups.end(), groups.begin(), groups.end());
}

bool Mere::Config::Group::valid() const
{
    return !m_name.empty();
}
