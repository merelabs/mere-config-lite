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
            std::string name = m_spec.group()->name(line);
            if (m_spec.group()->isSubGroup(line))
            {
                groupPtr = this->parent(groupPtr, m_spec.group()->parent(name));
                if (!groupPtr)
                {
                    if (strict() == Spec::Strict::Hard) throw Exception("malformed configuration");
                    else if (strict() != Spec::Strict::Soft) break;
                    continue;
                }

                std::string subgroup = m_spec.group()->subgroup(name);
                std::string base     = m_spec.group()->parent(name);

                Group *group = new Group(subgroup);
                group->path(base);
                group->parent(groupPtr);

                groupPtr->group(group);

                groupPtr = group;
            }
            else
            {
                Group *group = new Group(name);
                group->parent(nullptr);
                groups.push_back(group);

                groupPtr = group;
            }

            continue;
        }

        if (!groupPtr)
        {
            if (strict() == Spec::Strict::Hard) throw Exception("malformed configuration");
            else if (strict() != Spec::Strict::Soft) break;
            continue;
        }

        if (!m_spec.isProperty(line))
        {
            if (strict() == Spec::Strict::Hard) throw Exception("malformed configuration");
            else if (strict() != Spec::Strict::Soft) break;
            continue;
        }

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

    Group *group = new Group(m_spec.group()->name(match));
    group->parent(nullptr);

    Group *groupPtr = group;

    std::string line;
    while (Parser::next(file, line))
    {
        if (m_spec.isGroup(line))
        {
            std::string name = m_spec.group()->name(line);
            if (!m_spec.group()->isSubGroup(line))
                break;

            groupPtr = this->parent(groupPtr, m_spec.group()->parent(name));
            if (!groupPtr)
            {
                if (strict() != Spec::Strict::None) throw Exception("malformed configuration");
                break;
            }

            // is sub group?
            std::string subgroup = m_spec.group()->subgroup(name);
            std::string base     = m_spec.group()->parent(name);

            Group *group = new Group(subgroup);
            group->path(base);
            group->parent(groupPtr);

            groupPtr->group(group);

            groupPtr = group;
            continue;
        }

        if (!m_spec.isProperty(line))
        {
            if (strict() == Spec::Strict::Hard) throw Exception("malformed configuration");
            else if (strict() != Spec::Strict::Soft) break;

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
            if (strict() == Spec::Strict::Hard) throw Exception("malformed configuration");
            else if (strict() != Spec::Strict::Soft) break;

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

Mere::Config::Group* Mere::Config::Parser::GKParser::parent(Group *node, const std::string &parent) const
{
    while (node && node->name().compare(parent))
        node = node->parent();

    return node;
}
