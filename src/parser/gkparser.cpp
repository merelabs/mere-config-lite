#include "gkparser.h"
#include "../exception.h"

#include <fstream>

Mere::Config::Parser::GKParser::GKParser(const GroupConfig &config)
    : GroupParser(config),
      m_config(config)
{

}

std::vector<Mere::Config::Group> Mere::Config::Parser::GKParser::parse() const
{
    std::vector<Mere::Config::Group> groups;

//    bool ignore = true;
//    Group *groupPtr = nullptr;

//    std::vector<std::string> lines = Parser::parse();
//    for(const std::string &line : lines)
//    {
//        if (m_config.isGroup(line))
//        {
//            std::string name = m_config.group(line);
//            // is sub group?
//            if (m_config.isSubGroup(line))
//            {
//                std::string subgroup = m_config.subgroup(name);
//                std::string parent   = m_config.parent(name);
//                std::string base     = m_config.parent(name);

//                if (groupPtr->name().compare(parent))
//                {
//                    if (strict()) throw Exception("malformed configuration");
//                    ignore = true;
//                    continue;
//                }

//                Group group(subgroup);
//                group.path(base);

//                groupPtr->group(group);
//                groupPtr = &groupPtr->groups().back();
//            }
//            else
//            {
//                Group group(name);
//                groups.push_back(group);
//                groupPtr = &groups.back();
//            }

//            ignore = false;
//            continue;
//        }

//        if (ignore)
//        {
//            if (strict()) throw Exception("malformed configuration");
//            continue;
//        }

//        std::string key = this->key(line);
//        if(key.empty())
//        {
//            if (strict()) throw Exception("malformed configuration");
//            continue;
//        }

//        if (groupPtr)
//            groupPtr->property(Property(key, this->value(line)));
//    }

    return groups;
}

Mere::Config::Group Mere::Config::Parser::GKParser::parse(const std::string &name, int *set) const
{
//    std::ifstream file(config().path());
//    if (!file.good())
//    {
//        if (set) *set = 0;
//        return Group();
//    }

//    std::string match(name);
//    if(!next(file, match))
//    {
//        if (set) *set = 0;
//        return Group();
//    }

//    Mere::Config::Group group(m_config.group(match));

//    Group *groupPtr = &group;

//    std::string line;
//    while (Parser::next(file, line))
//    {
//        if (m_config.isGroup(line))
//        {
//            std::string name = m_config.group(line);
//            if (!m_config.isSubGroup(line))
//                break;

//            // is sub group?
//            std::string subgroup = m_config.subgroup(name);
//            std::string parent   = m_config.parent(name);
//            std::string base     = m_config.parent(name);

//            if (groupPtr->name().compare(parent))
//            {
//                if (strict()) throw Exception("malformed configuration");
//                break;
//            }

//            Group group(subgroup);
//            group.path(base);
//            groupPtr->group(group);
//            groupPtr = &groupPtr->groups().back();
//            continue;
//        }

//        std::string key = this->key(line);
//        if(key.empty())
//        {
//            if (strict()) throw Exception("malformed configuration");
//            continue;
//        }

//        std::string value = this->value(line);
//        groupPtr->property(Property(key, value));
//    }

//    if (set) *set = 1;

//    return group;
    return Group();
}

Mere::Config::Property Mere::Config::Parser::GKParser::parse(const std::string &group, const std::string &property, int *set) const
{
//    std::ifstream file(config().path());
//    if (!file.good())
//    {
//        if (set) *set = 0;
//        return Property();
//    }

//    std::string match(group);
//    if(!next(file, match))
//    {
//        if (set) *set = 0;
//        return Property();
//    }

//    Property _property;

//    std::string line;
//    while (Parser::next(file, line))
//    {
//        if (m_config.isGroup(line))
//            break;

//        std::string key = this->key(line);
//        if(key.empty())
//        {
//            if (strict()) throw Exception("malformed configuration");
//            continue;
//        }

//        if (key.compare(key) != 0)
//            continue;

//        _property.name(property);
//        _property.value(this->value(line));
//        break;
//    }

//    if (set) *set = _property.valid();

//    return _property;

    return Property();
}
