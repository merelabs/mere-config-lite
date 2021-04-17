#include "gkparser.h"
#include "../exception.h"

#include <fstream>

Mere::Config::Parser::GKParser::GKParser(const Spec::BaseEx &spec)
    : GroupParser(spec),
      m_spec(spec)
{
}

std::vector<Mere::Config::Group *> Mere::Config::Parser::GKParser::parse() const
{
    std::ifstream file(config().path());
    if (!file.good()) return {};

    std::vector<Mere::Config::Group *> groups;

    Group *groupPtr = nullptr;

    std::string line;
    while (Parser::next(file, line))
    {
        if (m_spec.isGroup(line))
        {
            std::string name = this->group(line);

            // is sub group?
            if (m_spec.group()->isSubGroup(line))
            {
                std::string subgroup = this->subgroup(name);
                std::string parent   = this->parent(name);
                std::string base     = this->parent(name);

                while (groupPtr && groupPtr->name().compare(parent))
                {
                    if (!groupPtr->parent())
                    {
                        if (strict()) throw Exception("malformed configuration");

                        groupPtr = nullptr;
                        continue;
                    }
                    groupPtr = groupPtr->parent();
                }

                Group *group = new Group(subgroup);
                group->path(base);
                group->parent(groupPtr);

                groupPtr->group(group);

                groupPtr = group;
            }
            else
            {
                Group *group = new Group(name);
                groups.push_back(group);

                groupPtr = group;
            }

            continue;
        }

        if (!groupPtr)
        {
            if (strict()) throw Exception("malformed configuration");
            continue;
        }

        if (!m_spec.isProperty(line))
        {
            if (strict()) throw Exception("malformed configuration");
            continue;
        }

        if (groupPtr)
            groupPtr->property(new Property(this->key(line), this->value(line)));
    }

    return groups;
}

Mere::Config::Group* Mere::Config::Parser::GKParser::parse(const std::string &name) const
{
    if (name.empty()) return nullptr;

    std::ifstream file(config().path());
    if (!file.good()) return nullptr;

    // FIXME
    std::string match("[" + name + "]");
    if(!seek(file, match)) return nullptr;

    Group *group = new Group(this->group(match));
    group->parent(nullptr);

    Group *groupPtr = group;

    std::string line;
    while (Parser::next(file, line))
    {
        if (m_spec.isGroup(line))
        {
            std::string name = this->group(line);
            if (!m_spec.group()->isSubGroup(line))
                break;

            // is sub group?
            std::string subgroup = this->subgroup(name);
            std::string parent   = this->parent(name);
            std::string base     = this->parent(name);

            while (groupPtr->name().compare(parent))
            {
                if (!groupPtr->parent())
                {
                    if (strict()) throw Exception("malformed configuration");
                    break;
                }
                groupPtr = groupPtr->parent();
            }

            Group *group = new Group(subgroup);
            group->path(base);
            group->parent(groupPtr);

            groupPtr->group(group);

            groupPtr = group;
            continue;
        }

        if (!m_spec.isProperty(line))
        {
            if (strict()) throw Exception("malformed configuration");
            continue;
        }

        groupPtr->property(new Property(this->key(line), this->value(line)));
    }

    return group;
}

Mere::Config::Property* Mere::Config::Parser::GKParser::parse(const std::string &name, const std::string &key) const
{
    std::ifstream file(config().path());
    if (!file.good()) return nullptr;

    if (!name.empty())
    {
        // FIXME delimiter
        std::string match("[" + name + "]");
        if(!seek(file, match)) return nullptr;
    }

    Property *property = nullptr;

    std::string line;
    while (Parser::next(file, line))
    {
        if (m_spec.isGroup(line))
            break;

        if (!m_spec.isProperty(line))
        {
            if (strict()) throw Exception("malformed configuration");
            continue;
        }

        std::string _key = this->key(line);
        if (_key.compare(key) != 0)
            continue;

        property = new Property(key, this->value(line));
        break;
    }

    return property;
}
