#include "dotparser.h"
#include "exception.h"
#include "mere/utils/stringutils.h"

#include <fstream>

Mere::Config::DotParser::DotParser(const DotConfig &config, QObject *parent)
    : GroupParser(config, parent),
      m_config(config)
{

}

bool Mere::Config::DotParser::isGroup(const std::string &line) const
{
//    return m_config.isGroup(line);

    auto pos = line.find('=');
    if (pos == std::string::npos)
        return false;

    auto dot = line.find('.');
    if (dot == std::string::npos)
        return false;

    if (dot > pos)
        return false;

    return true;
}

std::string Mere::Config::DotParser::group(const std::string &line) const
{
//    return m_config.group(line);

    if (!isGroup(line)) return "";

    auto pos = line.find('=');
    if (pos == std::string::npos)
        return "";

    auto dot = line.rfind(".", pos);
    if (dot == std::string::npos)
        return "";

    qDebug() << "LINE:" << line.c_str();
    qDebug() << "GROUP:" << line.substr(0, dot).c_str();

    return line.substr(0, dot);
}

std::vector<Mere::Config::Property> Mere::Config::DotParser::parse() const
{
    std::ifstream file(config().path());
    if (!file.good()) return {};

    std::vector<Mere::Config::Property> properties;

    std::string line;
    while (next(file, line))
    {
        if (!this->isGroup(line))
        {
            if (strict()) throw Exception("malformed configuration");
            continue;
        }

        std::string key   = this->key(line);
        if(key.empty())
        {
            if (strict()) throw Exception("malformed configuration");
            continue;
        }

        std::string value = this->value(line);

        properties.push_back(Property(key, value));
    }

    return properties;
}

std::vector<Mere::Config::Property> Mere::Config::DotParser::parse(const std::string &group, int *set) const
{
    std::ifstream file(config().path());
    if (!file.good())
    {
        if (set) *set = 0;
        return {};
    }

    std::string match(group + ".");

    std::vector<Mere::Config::Property> properties;

    std::string line;
    while (next(file, line))
    {
        if (!this->isGroup(line))
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

        auto pos = key.find(match);
        if (pos != 0) continue;


        std::string value = this->value(line);
        properties.push_back(Property(key, value));
    }

    if (set) *set = properties.size() ? 1 : 0;

    return properties;
}

std::string Mere::Config::DotParser::parse(const std::string &group, const std::string &property, int *set) const
{
    std::ifstream file(config().path());
    if (!file.good())
    {
        if (set) *set = 0;
        return {};
    }

    std::string match(group + "." + property);

    std::string value;
    bool found = false;

    std::string line;
    while (next(file, line))
    {
        if (!this->isGroup(line))
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

        if (key.compare(match)) continue;

        std::string value = this->value(line);
        found = true;
        break;
    }

    if (set) *set = found;

    return value;
}
