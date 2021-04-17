#include "kvparser.h"
#include "../exception.h"

#include "mere/utils/stringutils.h"

#include <fstream>

Mere::Config::Parser::KVParser::KVParser(const Spec::Base &spec)
    : PropertyParser(spec),
      m_spec(spec)
{

}

std::vector<Mere::Config::Property *> Mere::Config::Parser::KVParser::parse() const
{
    std::vector<Mere::Config::Property *> properties;

    std::string path = m_spec.path();

    std::ifstream file(path);
    if (!file.good()) return {};

    std::vector<std::string> lines;

    std::string line;
    while (PropertyParser::next(file, line))
    {
        properties.push_back(new Property(key(line), value(line)));
    }

    return properties;
}

Mere::Config::Property* Mere::Config::Parser::KVParser::parse(const std::string &key) const
{
    std::string match(key);
    // append property delimiter
    match.append(m_spec.property()->delimiter());

    int set;
    std::string line = Parser::parse(match, &set);
    if (!set) return nullptr;

    if (!m_spec.isProperty(line))
    {
        if (strict()) throw Exception("malformed configuration");
        return nullptr;
    }

    return new Property(key, value(line));
}
