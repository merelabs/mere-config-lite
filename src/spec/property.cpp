#include "property.h"

Mere::Config::Spec::Property::~Property()
{

}

Mere::Config::Spec::Property::Property()
    : Property("^([\\w._]+)=(.*)$")
{

}

Mere::Config::Spec::Property::Property(const std::string &pattern)
    : Domain(pattern),
      m_delimiter("="),
      m_key(nullptr),
      m_value(nullptr)
{

}

std::string Mere::Config::Spec::Property::delimiter() const
{
    return m_delimiter;
}

void Mere::Config::Spec::Property::delimiter(const std::string &delimiter)
{
    m_delimiter = delimiter;
}


bool Mere::Config::Spec::Property::isProperty(const std::string &line) const
{
    if (m_key && !isKey(line))      return false;
    if (m_value && !isValue(line))  return false;

    return valid(line);
}

Mere::Config::Spec::Key* Mere::Config::Spec::Property::key() const
{
    return m_key;
}

void Mere::Config::Spec::Property::key(Key *key)
{
    m_key = key;
}

bool Mere::Config::Spec::Property::isKey(const std::string &line) const
{
    return m_key->valid(line);
}

Mere::Config::Spec::Value* Mere::Config::Spec::Property::value() const
{
    return m_value;
}

void Mere::Config::Spec::Property::value(Value *value)
{
    m_value = value;
}

bool Mere::Config::Spec::Property::isValue(const std::string &line) const
{
    return m_value->valid(line);
}
