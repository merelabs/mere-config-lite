#include "iniparser.h"
#include "../property.h"
#include "../exception.h"

#include "mere/utils/stringutils.h"

#include <fstream>

Mere::Config::Parser::IniParser::IniParser(const Spec::Document &spec)
    : DocumentParser(spec),
      m_spec(spec)
{
}

std::string Mere::Config::Parser::IniParser::group(const std::string &line) const
{
    return line.substr(1, line.length() - 2);
}

std::string Mere::Config::Parser::IniParser::subgroup(const std::string &group) const
{
    auto pos = group.find_last_of(m_spec.group()->delimiter());
    return group.substr(pos + 1);
}

std::string Mere::Config::Parser::IniParser::parent(const std::string &group) const
{
    auto pos2 = group.find_last_of(m_spec.group()->delimiter());
    if (pos2 == std::string::npos)
        return "";

    auto pos1 = group.find_last_of(m_spec.group()->delimiter(), pos2 - 1);
    if (pos1 == std::string::npos)
        pos1 = -1;

    return group.substr(pos1 + 1, pos2 - pos1 -1 );
}

std::string Mere::Config::Parser::IniParser::base(const std::string &group) const
{
    auto pos = group.find_last_of(m_spec.group()->delimiter());
    if (pos == std::string::npos)
        return "";

    return group.substr(0, pos);
}

Mere::Config::Document* Mere::Config::Parser::IniParser::   parse() const
{
    std::string path = m_spec.path();

    std::ifstream file(path);
    if (!file.good()) return nullptr;

    Document *document = new Document(m_spec.path());

    // root group
    RootGroup *root = new RootGroup();

    std::vector<Mere::Config::Group *> groups;

    Group *groupPtr = root;

    std::vector<std::string> lines = Parser::parse();

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

        std::string key = this->key(line);
        if(key.empty())
        {
            if (strict()) throw Exception("malformed configuration");
            continue;
        }

        if (groupPtr)
            groupPtr->property(new Property(key, this->value(line)));
    }

    root->groups(groups);
    document->root(root);

    return document;
}

Mere::Config::Group* Mere::Config::Parser::IniParser::parse(const std::string &name) const
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

        std::string key = this->key(line);
        if(key.empty())
        {
            if (strict()) throw Exception("malformed configuration");
            continue;
        }

        std::string value = this->value(line);
        groupPtr->property(new Property(key, value));
    }

    return group;
}

Mere::Config::Property* Mere::Config::Parser::IniParser::parse(const std::string &name, const std::string &key) const
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
        if(_key.empty())
        {
            if (strict()) throw Exception("malformed configuration");
            continue;
        }

        if (_key.compare(key) != 0)
            continue;

        property = new Property(key, this->value(line));
        break;
    }

    return property;
}
