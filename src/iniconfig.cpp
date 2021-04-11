#include "iniconfig.h"
#include "parser/iniparser.h"

Mere::Config::IniConfig::IniConfig(const std::string &path, QObject *parent)
    : CrossConfig(path, ".ini", parent)
{

}

std::vector<std::string> Mere::Config::IniConfig::getKeys() const
{
    std::vector<std::string> keys;

    for(const Property &property : m_group.properties())
            keys.push_back(property.name());

    return keys;
}

std::vector<std::string> Mere::Config::IniConfig::getAllKeys() const
{
    std::vector<std::string> keys;

    std::vector<Property> prooerties = getProperties(m_group);

    for(const Property &property : prooerties)
            keys.push_back(property.name());

    return keys;
}

std::vector<std::string> Mere::Config::IniConfig::getKeys(const std::string &group, int *set) const
{
    auto it = std::find_if(m_group.groups().cbegin(), m_group.groups().cend(), [&](const Group &grp){
        return grp.name().compare(group) == 0;
    });

    if (it == m_group.groups().cend())
    {
        if (set) *set = 0;
        return {};
    }

    if (set) *set = 1;

    return getKeys(*it);
}

std::vector<std::string> Mere::Config::IniConfig::getAllKeys(const std::string &group, int *set) const
{
    auto it = std::find_if(m_group.groups().cbegin(), m_group.groups().cend(), [&](const Group &grp){
        return grp.name().compare(group) == 0;
    });

    if (it == m_group.groups().cend())
    {
        if (set) *set = 0;
        return {};
    }

    if (set) *set = 1;

    return getKeys(*it);
}

std::vector<std::string> Mere::Config::IniConfig::getKeys(const Group &group) const
{
    std::vector<std::string> keys;
    std::vector<Property> prooerties = getProperties(group);
    for(const Property &property : prooerties)
            keys.push_back(property.name());

    return keys;
}

std::vector<Mere::Config::Group> Mere::Config::IniConfig::getGroups() const
{
    return m_group.groups();
}

std::vector<Mere::Config::Group> Mere::Config::IniConfig::getAllGroups() const
{
    // implement it...
}


std::vector<Mere::Config::Group> Mere::Config::IniConfig::getGroups(const std::string &group, int *set) const
{
    Group grp = getGroup(group, set);
    if (!set) return {};

    return grp.groups();
}

std::vector<Mere::Config::Group> Mere::Config::IniConfig::getAllGroups(const std::string &group, int *set) const
{
    // implement recurssively
}

Mere::Config::Group Mere::Config::IniConfig::getGroup(const std::string &group, int *set) const
{
    if (group.empty())
    {
        if (set) *set = 0;
        return Group();
    }

    auto it = std::find_if(m_group.groups().cbegin(), m_group.groups().cend(), [&](const Group &grp){
        return grp.name().compare(group) == 0;
    });

    if (it == m_group.groups().cend())
    {
        if (set) *set = 0;
        return Group();
    }

    if (set) *set = 1;

    return *it;
}

std::string Mere::Config::IniConfig::getValue(const std::string &key, int *set) const
{
    auto pos = key.find_first_of("/");
    if(pos == std::string::npos)
    {
        if(set) *set = 0;
        return "";
    }

    return getValue(key.substr(0, pos), key.substr(pos + 1), set);
}

std::string Mere::Config::IniConfig::getValue(const std::string &group, const std::string &key, int *set) const
{
    return getValue(getGroup(group), key, set);
}

std::string Mere::Config::IniConfig::getValue(const Group &group, const std::string &key, int *set) const
{
    auto pos = key.find_first_of("/");
    if(pos != std::string::npos)
    {
        std::string section = key.substr(0, pos);

        auto groups = group.groups();
        auto it = std::find_if(groups.cbegin(), groups.cend(), [&](const Group &group){
            return group.name().compare(section) == 0;
        });

        if (it == groups.cend())
        {
            if(set) *set = 0;
            return "";
        }

        return getValue(*it, key.substr(pos + 1), set);
    }

    auto properties = group.properties();
    auto it = std::find_if(properties.cbegin(), properties.cend(), [&](const Property &property){
        return property.name().compare(key) == 0;
    });

    if (set) *set = (it != properties.cend());

    return set ? it->value() : "";
}

std::vector<Mere::Config::Property> Mere::Config::IniConfig::getProperties() const
{

}

std::vector<Mere::Config::Property> Mere::Config::IniConfig::getProperties(const std::string &group, int *set) const
{
   return getProperties(getGroup(group, set));
}

std::vector<Mere::Config::Property> Mere::Config::IniConfig::getProperties(const Group &group) const
{
    std::vector<Property> properties;

    const std::string key(group.base() + "/" + group.name() + "/");
    for(const Property &property : group.properties())
    {
        properties.push_back(Property(std::string(key).append(property.name()), property.value()));
    }

    std::vector<Property> _properties = getProperties(group.groups());
    properties.insert(properties.end(), _properties.begin(), _properties.end());

    return properties;
}

void Mere::Config::IniConfig::load()
{
    m_document = readDocument();
}

Mere::Config::Document Mere::Config::IniConfig::readDocument() const
{
    Mere::Config::Parser::DocumentConfig config(this->path());
    Mere::Config::Parser::IniParser parser(config);
    return parser.parse();
}

std::vector<Mere::Config::Group> Mere::Config::IniConfig::readGroups() const
{
    Mere::Config::Parser::DocumentConfig config(this->path());
    Mere::Config::Parser::IniParser parser(config);

    Mere::Config::Document document = parser.parse();
    return document.root().groups();
}

Mere::Config::Group Mere::Config::IniConfig::readGroup(const std::string &name, int *set) const
{
    Mere::Config::Parser::DocumentConfig config(this->path());
    Mere::Config::Parser::IniParser parser(config);
    return parser.parse(name);
}

std::vector<Mere::Config::Property> Mere::Config::IniConfig::readProperties() const
{
    Mere::Config::Parser::DocumentConfig config(this->path());
    Mere::Config::Parser::IniParser parser(config);

    Mere::Config::Document document = parser.parse();

    return getProperties(document.root());
}

std::vector<Mere::Config::Property> Mere::Config::IniConfig::properties(const std::string &group, int *set) const
{
//    IniParser parser(*this);
//    Group grp = parser.parse(group, set);

//    return getProperties(grp);
}

std::vector<Mere::Config::Property> Mere::Config::IniConfig::properties(const Group &group, int *set) const
{
    return getProperties(group);
}

std::vector<Mere::Config::Property> Mere::Config::IniConfig::getProperties(std::vector<Group> groups) const
{
    std::vector<Property> properties;

    for(const Group &group : groups)
    {
        std::vector<Property> _properties = getProperties(group);
        properties.insert(properties.end(), _properties.begin(), _properties.end());
    }

    return properties;;
}

std::vector<Mere::Config::Property> Mere::Config::IniConfig::getProperties(std::vector<Group> groups) const
{
    std::vector<Property> properties;

    for(const Group &group : groups)
    {
        std::vector<Property> _properties = getProperties(group);
        properties.insert(properties.end(), _properties.begin(), _properties.end());
    }

    return properties;;
}

