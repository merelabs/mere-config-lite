#include "iniparser.h"
#include "property.h"
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

std::vector<Mere::Config::Group> Mere::Config::IniParser::parse() const
{
    std::vector<Mere::Config::Group> groups;

    std::vector<std::string> lines = Parser::parse();
    for(const std::string &line : lines)
    {
        if (this->isGroup(line))
        {
            std::string name = line.substr(1, line.length() - 2);

            Group group(name);
            groups.push_back(group);
            continue;
        }
        if (groups.empty()) continue;

        std::string key = this->key(line);
        if(key.empty()) continue;

        std::string value = this->value(line);

        groups.back().property(Property(key, value));
    }

    return groups;
}

Mere::Config::Group Mere::Config::IniParser::parse(const std::string &match) const
{
    Mere::Config::Group group;

    std::string path = this->config().path();

    std::ifstream file(path);
    if (!file.good()) return group;

    bool found = false;

    std::string line;
    while (next(file, line))
    {
        if (this->isGroup(line))
        {
            if (found) break;

            std::string name = line.substr(1, line.length() - 2);

            if(line.compare(match) != 0)
                continue;

            group.name(name);

            found = true;
            continue;
        }

        if (!found) continue;

        std::string key = this->key(line);
        if(key.empty()) continue;

        std::string value = this->value(line);

        group.property(Property(key, value));
    }

    return group;
}
