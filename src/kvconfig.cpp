#include "kvconfig.h"
#include "parser/kvparser.h"

#include <fstream>
#include <iostream>

Mere::Config::KVConfig::~KVConfig()
{

}

Mere::Config::KVConfig::KVConfig(const std::string &path)
    : KVConfig(path, ".conf")
{
}

Mere::Config::KVConfig::KVConfig(const std::string &path, const std::string &type)
    : PropertyConfig(path, type)
{
}

std::string Mere::Config::KVConfig::get(const std::string &key, int *set) const
{
    auto it = std::find_if(m_properties.cbegin(), m_properties.cend(), [&](const Property *property){
        return property->name().compare(key) == 0;
    });

    if (it == m_properties.end())
    {
        if (set) *set  = 0;
        return "";
    }

    if (set) *set  = 1;
    return (*it)->value();
}

void Mere::Config::KVConfig::set(const std::string &key, const std::string &value)
{
    auto it = std::find_if(m_properties.begin(), m_properties.end(), [&](const Property *property){
        return property->name().compare(key) == 0;
    });

    if (it != m_properties.end())
        (*it)->value(value);
    else
        m_properties.push_back(new Property(key, value));
}

std::string Mere::Config::KVConfig::read(const std::string &key, int *set) const
{
    std::string value;

    Mere::Config::Spec::Base config(this->path());
    Mere::Config::Parser::KVParser parser(config);

    Property *property = parser.parse(key);
    if (property)
    {
        if (set) *set = 1;
        value = property->value();
        delete property;
    }
    else
    {
        if (set) *set = 0;
    }

    return value;
}

std::vector<std::string> Mere::Config::KVConfig::getKeys() const
{
    std::vector<std::string> keys;

    for(const auto *property : m_properties)
        keys.push_back(property->name());

    return keys;
}

std::string Mere::Config::KVConfig::getValue(const std::string &key, int *set) const
{
    return get(key, set);
}

Mere::Config::Property* Mere::Config::KVConfig::getProperty(const std::string &key) const
{
    auto it = std::find_if(m_properties.begin(), m_properties.end(), [&](const Property *property){
        return property->name().compare(key) == 0;
    });

    if (it == m_properties.end())
        return nullptr;

    return *it;
}

std::vector<Mere::Config::Property *> Mere::Config::KVConfig::getProperties() const
{
    return m_properties;
}

void Mere::Config::KVConfig::setProperty(Property *property)
{
    set(property->name(), property->value());
}

void Mere::Config::KVConfig::setValue(const std::string &key, const std::string &value)
{
    set(key, value);
}

std::vector<Mere::Config::Property *> Mere::Config::KVConfig::readProperties() const
{
    Mere::Config::Spec::Base config(this->path());
    Mere::Config::Parser::KVParser parser(config);
    return parser.parse();
}

Mere::Config::Property* Mere::Config::KVConfig::readProperty(const std::string &key) const
{
    Mere::Config::Spec::Base config(this->path());
    Mere::Config::Parser::KVParser parser(config);

    return parser.parse(key);
}

void Mere::Config::KVConfig::load()
{
    m_properties = this->readProperties();
}
