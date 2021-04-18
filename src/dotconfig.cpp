#include "dotconfig.h"
#include "parser/dotparser.h"

#include <QDebug>
Mere::Config::DotConfig::DotConfig(const std::string &path)
    : PropertyConfig(path, ".ini"),
      m_config(path)
{

}

std::string Mere::Config::DotConfig::get(const std::string &fqkp, int *set) const
{
    Property *property = getProperty(fqkp);
    if (!property)
    {
        if (set) *set = 0;
        return "";
    }

    if (set) *set = 1;

    return property->value();
}

void Mere::Config::DotConfig::set(const std::string &fqkp, const std::string &value)
{
    Property *property = getProperty(fqkp);
    if (!property)
    {
        m_properties.push_back(new Property(fqkp, value));
        return;
    }

    property->value(value);
}

std::string Mere::Config::DotConfig::read(const std::string &fqkp, int *set) const
{
    Mere::Config::Parser::DotParser parser(m_config);

    Property *property = parser.parseProperty(fqkp);;
    if (!property)
    {
        if (set) *set = 0;
        return "";
    }

    std::string value = property->value();
    delete property;

    if (set) *set = 1;

    return value;
}

std::vector<std::string> Mere::Config::DotConfig::getKeys() const
{
    std::vector<std::string> keys;

    for(const Property *property : m_properties)
        keys.push_back(property->name());

    return keys;
}

std::string Mere::Config::DotConfig::getValue(const std::string &key, int *set) const
{
    return get(key, set);
}

Mere::Config::Property* Mere::Config::DotConfig::getProperty(const std::string &key) const
{
    auto it = std::find_if(m_properties.cbegin(), m_properties.cend(), [&](const Property *property){
        return property->name().compare(key) == 0;
    });

    return it != m_properties.cend() ? *it : nullptr;
}

std::vector<Mere::Config::Property *> Mere::Config::DotConfig::getProperties() const
{
    return m_properties;
}

void Mere::Config::DotConfig::setProperty(Property *property)
{
    Mere::Config::Property* _property = getProperty(property->name());
    if (!_property)
    {
        m_properties.push_back(property);
        return;
    }

    _property->value(property->value());
}

void Mere::Config::DotConfig::setValue(const std::string &key, const std::string &value)
{
    set(key, value);
}

std::vector<Mere::Config::Property *> Mere::Config::DotConfig::readProperties() const
{
    Mere::Config::Parser::DotParser parser(m_config);

    return parser.parseProperties();;
}

Mere::Config::Property* Mere::Config::DotConfig::readProperty(const std::string &key) const
{
    Mere::Config::Parser::DotParser parser(m_config);
    return parser.parseProperty(key);;
}

std::vector<std::string> Mere::Config::DotConfig::getKeys(const std::string &name, int *set) const
{
    std::vector<std::string> keys;

    for(const Property *property : m_properties)
    {
        auto pos = property->name().find_last_of(".");
        if (pos == std::string::npos) continue;

        if (name.length() != pos) continue;

        if(property->name().substr(0, pos).compare(name))
            continue;

        keys.push_back(property->name());
    }
    return keys;
}

std::vector<std::string> Mere::Config::DotConfig::getAllKeys(const std::string &name, int *set) const
{
    std::vector<std::string> keys;

    for(const Property *property : m_properties)
    {
        if(property->name().find(name) != 0)
            continue;

        keys.push_back(property->name());
    }

    return keys;
}

std::vector<Mere::Config::Property *> Mere::Config::DotConfig::getProperties(const std::string &name, int *set) const
{
    std::vector<Mere::Config::Property *> properties;

    for(Property *property : m_properties)
    {
        auto pos = property->name().find_last_of(".");
        if (pos == std::string::npos) continue;

        if (name.length() != pos) continue;

        if(property->name().substr(0, pos).compare(name))
            continue;

        properties.push_back(property);
    }

    return properties;
}

std::vector<Mere::Config::Property *> Mere::Config::DotConfig::getAllProperties(const std::string &name, int *set) const
{
    std::vector<Mere::Config::Property *> properties;

    for(Property *property : m_properties)
    {
        if(property->name().find(name) != 0)
            continue;

        properties.push_back(property);
    }

    return properties;
}

//----
void Mere::Config::DotConfig::load()
{
    m_properties = this->readProperties();
}
