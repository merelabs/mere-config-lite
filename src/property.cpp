#include "property.h"
#include "group.h"

Mere::Config::Property::Property(const std::string &name)
    : m_name(name)
{
}

Mere::Config::Property::Property(const std::string &name, const std::string &value)
    : m_name(name),
      m_value(value)
{
}

std::string Mere::Config::Property::name() const
{
    return m_name;
}

void Mere::Config::Property::name(const std::string &name)
{
    m_name = name;
}

std::string Mere::Config::Property::value() const
{
    return m_value;
}

void Mere::Config::Property::value(const std::string &value)
{
    m_value = value;
}

std::string Mere::Config::Property::path() const
{
    return m_path;
}

void Mere::Config::Property::path(const std::string &path)
{
    m_path = path;
}

Mere::Config::Group* Mere::Config::Property::group() const
{
    return m_group;
}

void Mere::Config::Property::group(Mere::Config::Group *group)
{
    m_group = group;
}

bool Mere::Config::Property::valid() const
{
    return !m_name.empty();
}
