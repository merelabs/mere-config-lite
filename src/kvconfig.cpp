#include "kvconfig.h"
#include "parser/kvparser.h"

#include <fstream>
#include <iostream>

Mere::Config::KVConfig::~KVConfig()
{

}

Mere::Config::KVConfig::KVConfig(const std::string &path, QObject *parent)
    : KVConfig(path, ".conf", parent)
{
}

Mere::Config::KVConfig::KVConfig(const std::string &path, const std::string &type, QObject *parent)
    : PropertyConfig(path, type, parent)
{
}

std::string Mere::Config::KVConfig::get(const std::string &key, int *set) const
{
    std::string value;

    auto it = std::find_if(m_properties.begin(), m_properties.end(), [&](const Property &property){
        return property.name().compare(key) == 0;
    });

    if (it != m_properties.end())
        value = it->value();

    if (set) *set = it != m_properties.end();

    return value;
}

void Mere::Config::KVConfig::set(const std::string &key, const std::string &value)
{
    setValue(key, value);
}

std::string Mere::Config::KVConfig::read(const std::string &key, int *set) const
{
    Mere::Config::Parser::PropertyConfig config(this->path());
    Mere::Config::Parser::KVParser parser(config);

    Property property = parser.parse(key, set);

    return property.value();
}

//
//---------------------------------------------------------------------------------
//

std::vector<std::string> Mere::Config::KVConfig::getKeys() const
{
    std::vector<std::string> keys;

    for(const auto &property : m_properties)
        keys.push_back(property.name());

    return keys;
}

std::string Mere::Config::KVConfig::getValue(const std::string &key, int *set) const
{
    return get(key, set);
}

Mere::Config::Property Mere::Config::KVConfig::getProperty(const std::string &key, int *set) const
{
    return Property(key, getValue(key, set));
}

std::vector<Mere::Config::Property> Mere::Config::KVConfig::getProperties() const
{
    return m_properties;
}

void Mere::Config::KVConfig::setProperty(const Property &property)
{
    m_properties.push_back(property);
}

void Mere::Config::KVConfig::setValue(const std::string &key, const std::string &value)
{
    setProperty(Property(key, value));
}

std::vector<Mere::Config::Property> Mere::Config::KVConfig::readProperties() const
{
    Mere::Config::Parser::PropertyConfig config(this->path());
    Mere::Config::Parser::KVParser parser(config);
    return parser.parse();
}

Mere::Config::Property Mere::Config::KVConfig::readProperty(const std::string &key, int *set) const
{
    Mere::Config::Parser::PropertyConfig config(this->path());
    Mere::Config::Parser::KVParser parser(config);

    return parser.parse(key, set);
}

void Mere::Config::KVConfig::load()
{
    m_properties = this->readProperties();
}
