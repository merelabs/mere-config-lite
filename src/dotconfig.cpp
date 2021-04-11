#include "dotconfig.h"
#include "parser/dotparser.h"

#include <QDebug>
Mere::Config::DotConfig::DotConfig(const std::string &path, QObject *parent)
    : GroupConfig(path, ".ini", parent)
{

}

std::vector<std::string> Mere::Config::DotConfig::keys() const
{
    std::vector<std::string> keys;

    for(const auto &property : m_properties)
        keys.push_back(property.name());

    return keys;
}

std::vector<std::string> Mere::Config::DotConfig::keys(const std::string &group, int *set) const
{
    std::vector<std::string> keys;

    std::string prefix(group);
    prefix.append(".");

    for(const auto &property : m_properties)
    {
        auto pos = property.name().find(prefix);
        if (pos != 0) continue;

//FIXME
//        pos = property.name().find(".", prefix.length());
//        if (pos != std::string::npos) continue;

        keys.push_back(property.name());
    }

    return keys;
}

std::string Mere::Config::DotConfig::value(const std::string &key, int *set) const
{
    auto it = std::find_if(m_properties.cbegin(), m_properties.cend(), [&](const Property &property){
        return property.name().compare(key) == 0;
    });

    if (set) *set = (it != m_properties.cend());

    return *set ? it->value() : "";
}

std::string Mere::Config::DotConfig::value(const std::string &group, const std::string &key, int *set) const
{
    std::string fkey(group + "." + key);

    auto it = std::find_if(m_properties.cbegin(), m_properties.cend(), [&](const Property &property){
        return property.name().compare(fkey) == 0;
    });

    if (set) *set = (it != m_properties.cend());

    return *set ? it->value() : "";
}

Mere::Config::Property Mere::Config::DotConfig::get(const std::string &key) const
{
    int set;
    std::string value = this->value(key, &set);

    return set ? Property(key, value) : Property();
}

std::string Mere::Config::DotConfig::get(const std::string &key, int *set) const
{
    return value(key, set);
}

std::string Mere::Config::DotConfig::get(const std::string &group, const std::string &key, int *set) const
{
    return value(group, key, set);
}

std::map<std::string, std::string> Mere::Config::DotConfig::mget() const
{
    std::map<std::string, std::string> properties;

    for(const auto &property : m_properties)
        properties.insert({property.name(), property.value()});

    return properties;
}

std::map<std::string, std::string> Mere::Config::DotConfig::mget(const std::string &group, int *set) const
{
    std::map<std::string, std::string> properties;

    std::string prefix(group);
    prefix.append(".");

    for(const auto &property : m_properties)
    {
        auto pos = property.name().find(prefix);
        if (pos != 0) continue;

//FIXME
//        pos = property.name().find(".", prefix.length());
//        if (pos != std::string::npos) continue;

        properties.insert({ property.name(), property.value() });
    }

    if (set) *set = !properties.empty();

    return properties;
}

void Mere::Config::DotConfig::load()
{
    m_properties = this->properties();
}

std::vector<Mere::Config::Property> Mere::Config::DotConfig::properties() const
{
//    DotParser parser(*this);
//    return parser.parse();
}

std::vector<Mere::Config::Property> Mere::Config::DotConfig::properties(const std::string &group, int *set) const
{
//    DotParser parser(*this);
//    return parser.parse(group, set);
}

Mere::Config::Property Mere::Config::DotConfig::property(const std::string &group, const std::string &key, int *set) const
{
//    DotParser parser(*this);
//    return parser.parse(group, key, set);
}

bool Mere::Config::DotConfig::isGroup(const std::string &line) const
{
    auto pos = line.find('=');
    if (pos == std::string::npos)
        return false;

    auto dot = line.find('.');
    if (dot == std::string::npos)
        return false;

    if (dot > pos)
        return false;

    return true;
}

std::string Mere::Config::DotConfig::name(const std::string &line) const
{
    if (!isGroup(line)) return "";

    auto pos = line.find('=');
    if (pos == std::string::npos)
        return "";

    auto dot = line.rfind(".", pos);
    if (dot == std::string::npos)
        return "";

    qDebug() << "LINE:" << line.c_str();
    qDebug() << "GROUP:" << line.substr(0, dot).c_str();

    return line.substr(0, dot);
}
