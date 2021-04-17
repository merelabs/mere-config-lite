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

Mere::Config::Group* Mere::Config::Parser::CKParser::parse() const
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
            std::string name = this->group(line);

            // is sub group?
            if (m_spec.group()->isSubGroup(line))
            {
                std::string subgroup = this->subgroup(name);
                std::string parent   = this->parent(name);
                std::string base     = this->parent(name);

                while (groupPtr->name().compare(parent))
                {
                    if (!groupPtr->parent())
                    {
                        if (strict()) throw Exception("malformed configuration");
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

        if (!m_spec.isProperty(line))
        {
            if (strict()) throw Exception("malformed configuration");
            continue;
        }

        if (groupPtr)
            groupPtr->property(new Property(this->key(line), this->value(line)));
    }

    root->groups(groups);

    return root;
}

Mere::Config::Group* Mere::Config::Parser::CKParser::parse(const std::string &name) const
{
    GKParser parse(m_spec);
    return parse.parse(name);
}

Mere::Config::Property* Mere::Config::Parser::CKParser::parse(const std::string &name, const std::string &key) const
{
    GKParser parse(m_spec);
    return parse.parse(name, key);
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
            std::string name = this->group(line);

            // is sub group?
            if (m_spec.group()->isSubGroup(line))
            {
                std::string subgroup = this->subgroup(name);
                std::string parent   = this->parent(name);
                std::string base     = this->parent(name);

                while (groupPtr->name().compare(parent))
                {
                    if (!groupPtr->parent())
                    {
                        if (strict()) throw Exception("malformed configuration");
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
}
