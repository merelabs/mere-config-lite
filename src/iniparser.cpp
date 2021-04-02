#include "iniparser.h"
#include "mere/utils/stringutils.h"

#include <fstream>
#include <QDebug>

Mere::Config::IniParser::IniParser(const GroupConfig &config, QObject *parent)
    : GroupParser(config, parent)
{

}

std::map<std::string, std::map<std::string, std::string>> Mere::Config::IniParser::parse() const
{

    std::map<std::string, std::map<std::string, std::string>> properties;

    std::string path = this->config().path();

    std::ifstream file(path);

    // check for the file existance
    if (!file.good()) return properties;

    std::string section;
    std::string line;
    while (std::getline(file, line))
    {
        Mere::Utils::StringUtils::trim(line);

        if (line.empty()) continue;
        if (this->comment(line)) continue;

        if (this->section(line))
        {
            section = line.substr(1, line.length() - 2);
            properties.insert({section, {}});
            continue;
        }
        if (section.empty()) continue;

        std::string key = this->key(line);
        if(key.empty()) continue;

        std::string value = this->value(line);

        properties[section].insert({key, value});
    }

    return properties;
}
