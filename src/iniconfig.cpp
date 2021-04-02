#include "iniconfig.h"
#include "iniparser.h"

#include <QDebug>
Mere::Config::IniConfig::IniConfig(const std::string &path, QObject *parent)
    : GroupConfig(path, ".ini", parent)
{
    load();
}

std::vector<std::string> Mere::Config::IniConfig::sections() const
{
    std::vector<std::string> names;

    for(const auto &group : groups())
        names.push_back(group.name());

    return names;
}

std::map<std::string, std::string> Mere::Config::IniConfig::get(const std::string &section, int *set) const
{
    std::map<std::string, std::string> properties;

    Group group = this->group(section, set);
    if (!set) return properties;

    for(const auto &property : group.properties())
        properties.insert({property.name(), property.value()});

    return properties;
}

std::string Mere::Config::IniConfig::get(const std::string &section, const std::string &property, int *set) const
{
    Group group = this->group(section, set);
    if (!set) return "";


    for(const auto &_property : group.properties())
        if(_property.name().compare(property) == 0)
            return _property.value();

    return "";
}

void Mere::Config::IniConfig::load()
{
    m_config = this->properties();
}


std::map<std::string, std::map<std::string, std::string>> Mere::Config::IniConfig::properties() const
{
//    IniParser parser(path(), *this);
//    return parser.parse();
//    return {};

}

bool Mere::Config::IniConfig::isGroup(const std::string &line) const
{
    return line.front() == '[' && line.back() == ']';
}
