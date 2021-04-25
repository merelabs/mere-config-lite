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
            if (strict() != Spec::Base::Strict::None) throw Exception("malformed configuration");
            continue;
        }

        break;
    }

    return static_cast<bool>(file);
}
