#include "groupparser.h"
#include "../exception.h"

#include <fstream>

Mere::Config::Parser::GroupParser::GroupParser(const Spec::BaseEx &spec)
    : LineParser(spec),
      m_spec(spec)
{

}

bool Mere::Config::Parser::GroupParser::next(std::ifstream &file, std::string &line) const
{
    while(Parser::next(file, line))
    {
        if (m_spec.isGroup(line));
            break;
    }

    return static_cast<bool>(file);
}
