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
    return m_groups;
}

std::vector<Mere::Config::Group>& Mere::Config::Group::groups()
{
    return m_groups;
}

void Mere::Config::Group::group(const Group &group)
{
    m_groups.push_back(group);
}

void Mere::Config::Group::groups(const std::vector<Group> &groups)
{
    m_groups.clear();
    m_groups.insert(m_groups.end(), groups.begin(), groups.end());
}

std::string Mere::Config::Group::base() const
{
    return m_base;
}

void Mere::Config::Group::base(const std::string &base)
{
    m_base = base;
}

std::vector<std::string> Mere::Config::Group::keys() const
{
    std::vector<std::string> keys;

    for(const auto &property : m_properties)
        keys.push_back(property.name());

    return keys;
}

Mere::Config::Group Mere::Config::Group::group(const std::string &name) const
{
    auto it = std::find_if(m_groups.cbegin(), m_groups.cend(), [&](const Group &group){
        return group.name().compare(name) == 0;
    });

    if (it == m_groups.cend())
        return Group();

    return *it;
}

bool Mere::Config::Group::valid() const
{
    return !m_name.empty();
}

void Mere::Config::Group::dump() const
{
    std::cout << "Name::" << name() << std::endl;
    for(const auto &property : properties())
        std::cout << "Property::" << property.name() << " => " << property.value() << std::endl;

    for(const auto &subgroup : groups())
    {
        std::cout << "Subgroup::" << subgroup.name() << std::endl;
        for(const auto &property : subgroup.properties())
            std::cout << "Property::" << property.name() << " => " << property.value() << std::endl;
    }
}
