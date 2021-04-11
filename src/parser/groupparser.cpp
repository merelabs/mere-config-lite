#include "groupparser.h"
#include "../exception.h"

#include <fstream>

Mere::Config::Parser::GroupParser::GroupParser(const GroupConfig &config)
    : Parser(config),
      m_config(config)
{

}

bool Mere::Config::Parser::GroupParser::next(std::ifstream &file, std::string &line) const
{
    while(Parser::next(file, line))
    {
        if (m_config.isGroup(line));
            break;
    }

    return static_cast<bool>(file);
}
