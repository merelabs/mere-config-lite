#include "kvparser.h"
#include "../exception.h"

#include "mere/utils/stringutils.h"

#include <fstream>

Mere::Config::Parser::KVParser::KVParser(const PropertyConfig &config)
    : PropertyParser(config),
      m_config(config)
{

}

std::vector<Mere::Config::Property> Mere::Config::Parser::KVParser::parse() const
{
    std::vector<Mere::Config::Property> properties;

    std::string path = m_config.path();

    std::ifstream file(path);
    if (!file.good()) return {};

    std::vector<std::string> lines;

    std::string line;
    while (next(file, line))
    {
        if (!m_config.isProperty(line))
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

        properties.push_back(Property(key, value(line)));
    }

    return properties;
}

Mere::Config::Property Mere::Config::Parser::KVParser::parse(const std::string &key, int *set) const
{
    std::string match(key);
    match.append(m_config.delimiter());

    std::string line = Parser::parse(match, set);
    if (!set) return Property();

    if (!m_config.isProperty(line))
    {
        if (strict()) throw Exception("malformed configuration");
        return Property();
    }

    return Property(key, value(line));
}
