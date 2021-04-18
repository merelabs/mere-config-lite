#include "ckparser.h"
#include "gkparser.h"
#include "kvparser.h"
#include "gkparser.h"
#include "../exception.h"

#include <fstream>

Mere::Config::Parser::CKParser::CKParser(const Spec::BaseEx &spec)
    : CrossParser(spec),
      m_spec(spec)
{
}

Mere::Config::Group* Mere::Config::Parser::CKParser::parseGroup() const
{
    std::ifstream file(config().path());
    if (!file.good()) return nullptr;

    // root group
    Group *root = new Group();

    std::vector<Mere::Config::Group *> groups;

    Group *groupPtr = root;

    std::string line;
    while (Parser::next(file, line))
    {
        if (m_spec.isGroup(line))
        {
            std::string name = m_spec.group()->name(line);

            // is sub group?
            if (m_spec.group()->isSubGroup(line))
            {
                groupPtr = this->parent(groupPtr, m_spec.group()->parent(name));
                if (!groupPtr)
                {
                    if (strict()) throw Exception("malformed configuration");
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
                groups.push_back(group);

                groupPtr = group;
            }

            continue;
        }

        if (!m_spec.isProperty(line))
        {
            if (strict()) throw Exception("malformed configuration");
            continue;
        }

        groupPtr->property(new Property(this->key(line), this->value(line)));
    }

    root->groups(groups);

    return root;
}

Mere::Config::Group* Mere::Config::Parser::CKParser::parseGroup(const std::string &name) const
{
    GKParser parse(m_spec);
    return parse.parseGroup(name);
}

Mere::Config::Property* Mere::Config::Parser::CKParser::parseProperty(const std::string &key) const
{
    //FIXME
    return nullptr;
}

Mere::Config::Property* Mere::Config::Parser::CKParser::parseProperty(const std::string &name, const std::string &key) const
{
    GKParser parse(m_spec);
    return parse.parseProperty(name, key);
}

std::vector<Mere::Config::Property *> Mere::Config::Parser::CKParser::parseProperties() const
{
    std::ifstream file(config().path());
    if (!file.good()) return {};

    std::vector<Mere::Config::Property *> properties;

    std::string line;
    while (Parser::next(file, line))
    {
        if (!m_spec.isProperty(line))
            break;

        properties.push_back(new Property(this->key(line), this->value(line)));
    }

    return properties;
}

std::vector<Mere::Config::Group *> Mere::Config::Parser::CKParser::parseGroups() const
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

            // is sub group?
            if (m_spec.group()->isSubGroup(line))
            {
                groupPtr = this->parent(groupPtr, m_spec.group()->parent(name));
                if (!groupPtr)
                {
                    if (strict()) throw Exception("malformed configuration");
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

        groupPtr->property(new Property(this->key(line), this->value(line)));
    }
}

Mere::Config::Group* Mere::Config::Parser::CKParser::parent(Group *node, const std::string &parent) const
{
    while (node && node->name().compare(parent))
        node = node->parent();

    return node;
}
