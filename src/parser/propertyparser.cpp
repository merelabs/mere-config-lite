#include "propertyparser.h"
#include "../exception.h"

#include <fstream>

Mere::Config::Parser::PropertyParser::PropertyParser(const Spec::Base &spec)
    : LineParser(spec)
{

}

bool Mere::Config::Parser::PropertyParser::next(std::ifstream &file, std::string &line) const
{
    while(Parser::next(file, line))
    {
        if (!config().isProperty(line))
        {
            if (strict()) throw Exception("malformed configuration");
            continue;
        }

        break;
    }

    return static_cast<bool>(file);
}

//std::string Mere::Config::Parser::PropertyParser::key(const std::string &line) const
//{
//    auto pos = line.find(config().property()->delimiter());
//    if (pos == 0 || pos == std::string::npos) return "";

//    return line.substr(0, pos);
//}

//std::string Mere::Config::Parser::PropertyParser::value(const std::string &line) const
//{
//    auto pos = line.find(config().property()->delimiter());
//    if (pos == 0 || pos == std::string::npos) return "";

//    return line.substr(pos + 1);
//}
