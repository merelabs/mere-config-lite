#include "kvparser.h"
#include "mere/utils/stringutils.h"

#include <fstream>

Mere::Config::KVParser::KVParser(const KVConfig &config, QObject *parent)
    : Parser(config, parent)
{

}

std::vector<Mere::Config::Property> Mere::Config::KVParser::parse() const
{
    std::vector<Mere::Config::Property> properties;

    std::string path = this->config().path();

    // check for the file extension
    std::string ext(".conf");
    auto pos = path.find(ext);
    if (pos != path.length() - ext.length())
        return properties;

    std::ifstream file(path);

    // check for the file existance
    if (!file.good()) return properties;

    std::string line;
    while (std::getline(file, line))
    {
        Mere::Utils::StringUtils::trim(line);

        if (line.empty()) continue;
        if (this->isComment(line)) continue;

        std::string key   = this->key(line);
        if(key.empty()) continue;

        std::string value = this->value(line);

        properties.push_back(Property(key, value));
    }

    return properties;
}

std::string Mere::Config::KVParser::parse(const std::string &key, int *set) const
{
    std::string value;

    if (set) *set = 0;

    std::string path = this->config().path();

    // check for the file extension
    std::string ext(".conf");
    auto pos = path.find(ext);
    if (pos != path.length() - ext.length())
        return value;

    std::ifstream file(path);

    // check for the file existance
    if (!file.good()) return value;

    std::string line;
    while (std::getline(file, line))
    {
        Mere::Utils::StringUtils::trim(line);

        if (line.empty()) continue;
        if (this->isComment(line)) continue;

        std::string k   = this->key(line);
        if(k.empty()) continue;

        if (k != key) continue;

        value = this->value(line);
        if (set) *set = 1;
        break;
    }

    return value;
}

std::string Mere::Config::Parser::key(const std::string &line) const
{
    auto pos = line.find("=");
    if (pos == 0 || pos == std::string::npos) return "";

    return line.substr(0, pos);
}

std::string Mere::Config::Parser::value(const std::string &line) const
{
    auto pos = line.find("=");
    if (pos == 0 || pos == std::string::npos) return "";

    return line.substr(pos + 1);
}
