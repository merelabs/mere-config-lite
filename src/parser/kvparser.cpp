#include "kvparser.h"
#include "../exception.h"

#include <fstream>

Mere::Config::Parser::KVParser::KVParser(const Spec::Base &spec)
    : PropertyParser(spec)
{
}

std::vector<Mere::Config::Property *> Mere::Config::Parser::KVParser::parse() const
{
    std::ifstream file(config().path());
    if (!file.good()) return {};

    std::vector<Mere::Config::Property *> properties;

    try
    {
        std::string line;
        while (PropertyParser::next(file, line))
            properties.push_back(new Property(key(line), value(line)));
    }
    catch (Exception &e)
    {
        if (strict() == Spec::Base::Strict::Hard)
            throw Exception("malformed configuration");
    }

    return properties;
}

Mere::Config::Property* Mere::Config::Parser::KVParser::parse(const std::string &key) const
{
    std::string match(key);
    match.append(config().property()->delimiter());

    int set;
    std::string line = LineParser::parseLine(match, &set);
    if (!set) return nullptr;

    if (!config().isProperty(line))
    {
        if (strict() == Spec::Base::Strict::Hard) throw Exception("malformed configuration");
        return nullptr;
    }

    return new Property(key, value(line));
}
