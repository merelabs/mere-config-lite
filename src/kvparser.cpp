#include "kvparser.h"
#include "exception.h"

#include "mere/utils/stringutils.h"

Mere::Config::KVParser::KVParser(const KVConfig &config, QObject *parent)
    : Parser(config, parent)
{

}

std::vector<Mere::Config::Property> Mere::Config::KVParser::parse() const
{           
    std::vector<Mere::Config::Property> properties;

    std::vector<std::string> lines = Parser::parse();
    for(const std::string &line : lines)
    {
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

std::string Mere::Config::KVParser::parse(const std::string &key, int *set) const
{
    std::string match(key);
    match.append("=");

    std::string line = Parser::parse(match, set);
    if (line.empty()) return line;

    return this->value(line);
}

std::string Mere::Config::KVParser::key(const std::string &line) const
{
    auto pos = line.find("=");
    if (pos == 0 || pos == std::string::npos) return "";

    return line.substr(0, pos);
}

std::string Mere::Config::KVParser::value(const std::string &line) const
{
    auto pos = line.find("=");
    if (pos == 0 || pos == std::string::npos) return "";

    return line.substr(pos + 1);
}
