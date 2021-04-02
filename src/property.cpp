#include "property.h"

Mere::Config::Property::Property(const std::string &name)
    : m_name(name)
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
