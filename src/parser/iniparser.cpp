#include "iniparser.h"
#include "../property.h"
#include "../exception.h"

#include "mere/utils/stringutils.h"

#include <fstream>

Mere::Config::Parser::IniParser::IniParser(const DocumentConfig &config)
    : DocumentParser(config),
      m_config(config)
{

}

bool Mere::Config::Parser::IniParser::isGroup(const std::string &line) const
{
    return m_config.isGroup(line);
}

bool Mere::Config::Parser::IniParser::isSubGroup(const std::string &line) const
{
    return m_config.isSubGroup(line);
}

std::string Mere::Config::Parser::IniParser::group(const std::string &line) const
{
    return line.substr(1, line.length() - 2);
}

std::string Mere::Config::Parser::IniParser::subgroup(const std::string &group) const
{
    auto pos = group.find_last_of("/");
    return group.substr(pos + 1);
}

std::string Mere::Config::Parser::IniParser::parent(const std::string &group) const
{
    auto pos2 = group.find_last_of("/");
    if (pos2 == std::string::npos)
        return "";

    auto pos1 = group.find_last_of("/", pos2 - 1);
    if (pos1 == std::string::npos)
        pos1 = -1;

    return group.substr(pos1 + 1, pos2 - pos1 -1 );
}

std::string Mere::Config::Parser::IniParser::base(const std::string &group) const
{
    auto pos = group.find_last_of("/");
    if (pos == std::string::npos)
        return "";

    return group.substr(0, pos);
}

Mere::Config::Document Mere::Config::Parser::IniParser::parse() const
{
    Document document(m_config.path());

    // root group
    RootGroup root;

    std::vector<Mere::Config::Group> groups;

    Group *groupPtr = &root;

    std::vector<std::string> lines = Parser::parse();
    for(const std::string &line : lines)
    {
        if (this->isGroup(line))
        {
            std::string name = this->group(line);
            // is sub group?
            if (this->isSubGroup(line))
            {
                std::string subgroup = this->subgroup(name);
                std::string parent   = this->parent(name);
                std::string base     = this->parent(name);

                if (groupPtr->name().compare(parent))
                {
                    if (strict()) throw Exception("malformed configuration");
                    continue;
                }

                Group group(subgroup);
                group.base(base);

                groupPtr->group(group);
                groupPtr = &groupPtr->groups().back();
            }
            else
            {
                Group group(name);
                groups.push_back(group);
                groupPtr = &groups.back();
            }

            continue;
        }

        std::string key = this->key(line);
        if(key.empty())
        {
            if (strict()) throw Exception("malformed configuration");
            continue;
        }

        if (groupPtr)
            groupPtr->property(Property(key, this->value(line)));
    }

    root.groups(groups);
    document.root(root);

    return document;
}

Mere::Config::Group Mere::Config::Parser::IniParser::parse(const std::string &name, int *set) const
{
    std::ifstream file(config().path());
    if (!file.good())
    {
        if (set) *set = 0;
        return Group();
    }

    std::string match(name);
    if(!next(file, match))
    {
        if (set) *set = 0;
        return Group();
    }

    Mere::Config::Group group(this->group(match));

    Group *groupPtr = &group;

    std::string line;
    while (Parser::next(file, line))
    {
        if (this->isGroup(line))
        {
            std::string name = this->group(line);
            if (!this->isSubGroup(line))
                break;

            // is sub group?
            std::string subgroup = this->subgroup(name);
            std::string parent   = this->parent(name);
            std::string base     = this->parent(name);

            if (groupPtr->name().compare(parent))
            {
                if (strict()) throw Exception("malformed configuration");
                break;
            }

            Group group(subgroup);
            group.base(base);
            groupPtr->group(group);
            groupPtr = &groupPtr->groups().back();
            continue;
        }

        std::string key = this->key(line);
        if(key.empty())
        {
            if (strict()) throw Exception("malformed configuration");
            continue;
        }

        std::string value = this->value(line);
        groupPtr->property(Property(key, value));
    }

    if (set) *set = 1;


    return group;
}

Mere::Config::Property Mere::Config::Parser::IniParser::parse(const std::string &group, const std::string &property, int *set) const
{
    std::ifstream file(config().path());
    if (!file.good())
    {
        if (set) *set = 0;
        return Property();
    }

    std::string match(group);
    if(!next(file, match))
    {
        if (set) *set = 0;
        return Property();
    }

    Property _property;

    std::string line;
    while (Parser::next(file, line))
    {
        if (this->isGroup(line))
            break;

        std::string key = this->key(line);
        if(key.empty())
        {
            if (strict()) throw Exception("malformed configuration");
            continue;
        }

        if (key.compare(key) != 0)
            continue;

        _property.name(property);
        _property.value(this->value(line));
        break;
    }

    if (set) *set = _property.valid();

    return _property;
}
