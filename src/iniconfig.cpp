#include "iniconfig.h"
#include "parser/iniparser.h"

Mere::Config::IniConfig::IniConfig(const std::string &path)
    : CrossConfig(path, ".ini"),
      m_config(path)
{
    m_config.group("^\\\[\\\w+(\\\s+\\\w+)*(\\\/\\\w+(\\\s+\\\w+)*)*\\\]$");
}

std::string Mere::Config::IniConfig::get(const std::string &fqkp, int *set) const
{

    Property *property = m_document->property(fqkp);
    if (!property)
    {
        if (set) *set = 0;
        return "";
    }

    if (set) *set = 1;

    return property->value();
}

void Mere::Config::IniConfig::set(const std::string &fqkp, const std::string &value)
{
    Property *property = m_document->property(fqkp);
    if (property)
    {
        property->value(value);
        return;
    }

    auto pos = fqkp.find_last_of(m_config.delimiter());
    if (pos == std::string::npos)
    {
        m_document->root()->property(new Property(fqkp, value));
        return;
    }

    Group *group = m_document->group(fqkp.substr(0, pos));
    if (!group) return;

    group->property(new Property(fqkp.substr(pos + 1), value));
}

std::string Mere::Config::IniConfig::read(const std::string &fqkp, int *set) const
{
    Mere::Config::Parser::DocumentConfig config(this->path());
    Mere::Config::Parser::IniParser parser(config);

    std::string path, key(fqkp);

    auto pos = fqkp.find_last_of(m_config.delimiter());
    if (pos != std::string::npos)
    {
        path = fqkp.substr(0, pos);
        key  = fqkp.substr(pos + 1);
    }

    Property *property = parser.parse(path, key);;
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

std::vector<std::string> Mere::Config::IniConfig::getKeys() const
{
    return m_document->root()->keys();
}

std::vector<std::string> Mere::Config::IniConfig::getAllKeys() const
{
    return m_document->root()->keys(100);
}

std::vector<std::string> Mere::Config::IniConfig::getKeys(const std::string &name, int *set) const
{
    Group *group = m_document->group(name);
    if (!group)
    {
        if(set) *set = 0;
        return {};
    }
    if(set) *set = 1;

    return group->keys();
}

std::vector<std::string> Mere::Config::IniConfig::getAllKeys(const std::string &name, int *set) const
{
    Group *group = m_document->group(name);
    if (!group)
    {
        if(set) *set = 0;
        return {};
    }
    if(set) *set = 1;

    return group->keys(100);
}

Mere::Config::Group* Mere::Config::IniConfig::getGroup(const std::string &name) const
{
    return m_document->group(name);
}

std::vector<Mere::Config::Group *> Mere::Config::IniConfig::getGroups() const
{
    return m_document->root()->groups();
}

std::vector<Mere::Config::Group *> Mere::Config::IniConfig::getAllGroups() const
{
    return m_document->root()->groups(100);
}

std::vector<Mere::Config::Group *> Mere::Config::IniConfig::getGroups(const std::string &name, int *set) const
{
    Group *group = m_document->group(name);
    if (!group)
    {
        if(set) *set = 0;
        return {};
    }

    if(set) *set = 1;

    return group->groups();
}

std::vector<Mere::Config::Group *> Mere::Config::IniConfig::getAllGroups(const std::string &name, int *set) const
{
    Group *group = m_document->group(name);
    if (!group)
    {
        if(set) *set = 0;
        return {};
    }

    if(set) *set = 1;

    return group->groups(100);
}

std::string Mere::Config::IniConfig::getValue(const std::string &key, int *set) const
{
    return get(key, set);
}

std::string Mere::Config::IniConfig::getValue(const std::string &name, const std::string &key, int *set) const
{
    Group *group = m_document->group(name);
    if (!group)
    {
        if(set) *set = 0;
        return {};
    }

    return getValue(group, key, set);
}

// OK
std::string Mere::Config::IniConfig::getValue(const Group *group, const std::string &key, int *set) const
{
    Property *property = group->property(key);
    if (!property)
    {
        if(set) *set = 0;
        return {};
    }

    if(set) *set = 1;

    return property->value();
}

Mere::Config::Property* Mere::Config::IniConfig::getProperty(const std::string &key) const
{
    return m_document->property(key);
}

Mere::Config::Property* Mere::Config::IniConfig::getProperty(const std::string &name, const std::string &key) const
{
    Group *group = m_document->group(name);
    if (!group) return nullptr;

    return group->property(key);
}

std::vector<Mere::Config::Property *> Mere::Config::IniConfig::getProperties() const
{
    return m_document->root()->properties();
}

std::vector<Mere::Config::Property *> Mere::Config::IniConfig::getAllProperties() const
{
    return m_document->root()->properties(100);
}

std::vector<Mere::Config::Property *> Mere::Config::IniConfig::getProperties(const std::string &name, int *set) const
{
    Group *group = m_document->group(name);
    if (!group)
    {
        if(set) *set = 0;
        return {};
    }

    if(set) *set = 1;

    return group->properties();
}

std::vector<Mere::Config::Property *> Mere::Config::IniConfig::getAllProperties(const std::string &name, int *set) const
{
    Group *group = m_document->group(name);
    if (!group)
    {
        if(set) *set = 0;
        return {};
    }

    if(set) *set = 1;

    return group->properties(100);
}

void Mere::Config::IniConfig::setValue(const std::string &key, const std::string &value)
{
    set(key, value);
}

void Mere::Config::IniConfig::setProperty(Property *property)
{
    m_document->root()->property(property);
}

Mere::Config::Document* Mere::Config::IniConfig::readDocument() const
{
    Mere::Config::Parser::IniParser parser(m_config);
    return parser.parse();
}

Mere::Config::Group* Mere::Config::IniConfig::readGroup(const std::string &name) const
{
    Mere::Config::Parser::IniParser parser(m_config);

    return parser.parse(name);
}

std::vector<Mere::Config::Property *> Mere::Config::IniConfig::readProperties() const
{
    // IMPORVE WHY READ ALL??
    Mere::Config::Parser::IniParser parser(m_config);

    Mere::Config::Document *document = parser.parse();

    return document->root()->properties();
}


Mere::Config::Property* Mere::Config::IniConfig::readProperty(const std::string &key) const
{
    return readProperty("", key);
}

Mere::Config::Property* Mere::Config::IniConfig::readProperty(const std::string &name, const std::string &key) const
{
    Mere::Config::Parser::IniParser parser(m_config);

    return parser.parse(name, key);
}

void Mere::Config::IniConfig::load()
{
    m_document = readDocument();
}
