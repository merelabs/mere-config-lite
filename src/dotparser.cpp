#include "dotparser.h"
#include "mere/utils/stringutils.h"

#include <fstream>

Mere::Config::DotParser::DotParser(const DotConfig &config, QObject *parent)
    : GroupParser(config, parent),
      m_config(config)
{

}

bool Mere::Config::DotParser::isGroup(const std::string &line) const
{
    return m_config.isGroup(line);
}

std::vector<Mere::Config::Property> Mere::Config::DotParser::parse() const
{
    std::vector<Mere::Config::Property> properties;

    std::string path = this->config().path();

//    // check for the file extension
//    std::string ext(".conf");
//    auto pos = path.find(ext);
//    if (pos != path.length() - ext.length())
//        return properties;

    std::ifstream file(path);

    // check for the file existance
//    if (!file.good()) return properties;

    std::string line;
    while (std::getline(file, line))
    {
        Mere::Utils::StringUtils::trim(line);

        if (line.empty()) continue;
        if (this->isComment(line)) continue;
        if (!this->isGroup(line)) continue;

        std::string key   = this->key(line);
        if(key.empty()) continue;

        std::string value = this->value(line);

        properties.push_back(Property(key, value));
    }

    return properties;
}
