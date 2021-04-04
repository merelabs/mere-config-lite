#include "kvparser.h"
#include "mere/utils/stringutils.h"

Mere::Config::KVParser::KVParser(const KVConfig &config, QObject *parent)
    : Parser(config, parent)
{
    connect(this, SIGNAL(parsed(const std::string &) const), this, SLOT(parse(const std::string &)));
}

std::vector<Mere::Config::Property> Mere::Config::KVParser::parse() const
{           
    std::vector<Mere::Config::Property> properties;

    std::vector<std::string> lines = Parser::parse();
    for(const std::string &line : lines)
    {
        std::string key   = this->key(line);
        if(key.empty()) continue;

        std::string value = this->value(line);

        properties.push_back(Property(key, value));
    }

    return properties;
}

std::string Mere::Config::KVParser::parse(const std::string &key, int *set) const
{
    std::string value = Parser::parse(key, set);

    if (set) *set = !value.empty();

    return value;
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
