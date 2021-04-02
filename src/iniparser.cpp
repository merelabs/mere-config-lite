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

//    std::map<std::string, std::map<std::string, std::string>> properties;

    std::string path = this->config().path();

    std::ifstream file(path);

    // check for the file existance
    if (!file.good()) return groups;

    std::vector<Property> properties;

    std::string line;
    while (std::getline(file, line))
    {
        Mere::Utils::StringUtils::trim(line);

        if (line.empty()) continue;
        if (this->isComment(line)) continue;

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
