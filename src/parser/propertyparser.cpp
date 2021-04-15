#include "propertyparser.h"

#include <fstream>

Mere::Config::Parser::PropertyParser::PropertyParser(const Config &config)
    : Parser(config),
      m_config(config)
{

}

bool Mere::Config::Parser::PropertyParser::next(std::ifstream &file, std::string &line) const
{
    while(Parser::next(file, line))
    {
        if (m_config.isProperty(line));
            break;
    }

    return static_cast<bool>(file);
}
