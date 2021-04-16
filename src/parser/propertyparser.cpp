#include "propertyparser.h"

#include <fstream>

Mere::Config::Parser::PropertyParser::PropertyParser(const Spec::Base &spec)
    : Parser(spec),
      m_spec(spec)
{

}

bool Mere::Config::Parser::PropertyParser::next(std::ifstream &file, std::string &line) const
{
    while(Parser::next(file, line))
    {
        if (m_spec.isProperty(line));
            break;
    }

    return static_cast<bool>(file);
}
