#include "iniparser.h"
#include "property.h"
#include "exception.h"

#include "mere/utils/stringutils.h"

#include <fstream>
#include <QDebug>

Mere::Config::IniParser::IniParser(const GroupConfig &config, QObject *parent)
    : GroupParser(config, parent),
      m_config(config)
{

}

bool Mere::Config::IniParser::isGroup(const std::string &line) const
{
    return m_config.isGroup(line);
}

std::string Mere::Config::IniParser::group(const std::string &line) const
{
    return isGroup(line) ? line.substr(1, line.length() - 2) : "";
}

std::vector<Mere::Config::Group> Mere::Config::IniParser::parse() const
{
    std::vector<Mere::Config::Group> groups;

    std::vector<std::string> lines = Parser::parse();
    for(const std::string &line : lines)
    {
        if (this->isGroup(line))
        {
            Group group(this->group(line));
            groups.push_back(group);
            continue;
        }

        if (groups.empty())
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

        groups.back().property(Property(key, value));
    }

    return groups;
}

std::vector<Mere::Config::Property> Mere::Config::IniParser::parse(const std::string &section, int *set) const
{
    std::ifstream file(config().path());
    if (!file.good())
    {
        if (set) *set = 0;
        return {};
    }

    std::vector<Mere::Config::Property> properties;

    bool found = false;

    std::string line;
    while (next(file, line))
    {
        if (this->isGroup(line))
        {
            if (found) break;

            std::string group = this->group(line);
            if(group.compare(section) != 0)
                continue;

            found = true;
            continue;
        }

        if (!found) continue;

        std::string key = this->key(line);
        if(key.empty())
        {
            if (strict()) throw Exception("malformed configuration");
            continue;
        }

        std::string value = this->value(line);
        properties.push_back(Property(key, value));
    }

    if (set) *set = found;

    return properties;
}


std::string Mere::Config::IniParser::parse(const std::string &section, const std::string &property, int *set) const
{
    std::ifstream file(config().path());
    if (!file.good())
    {
        if (set) *set = 0;
        return "";
    }

    std::string value;

    bool gfound = false;
    bool pfound = false;

    std::string line;
    while (next(file, line))
    {
        if (this->isGroup(line))
        {
            if (gfound) break;

            std::string group = this->group(line);
            if(group.compare(section) != 0)
                continue;

            gfound = true;
            continue;
        }

        if (!gfound) continue;

        std::string key = this->key(line);
        if(key.empty())
        {
            if (strict()) throw Exception("malformed configuration");
            continue;
        }

        if (key.compare(property) != 0)
            continue;

        value = this->value(line);
        pfound = true;
        break;
    }

    if (set) *set = pfound;

    return value;
}
