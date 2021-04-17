#include "groupparser.h"
#include "../exception.h"

#include <fstream>

Mere::Config::Parser::GroupParser::GroupParser(const Spec::BaseEx &spec)
    : Parser(spec),
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

std::string Mere::Config::Parser::GroupParser::group(const std::string &line) const
{
    return line.substr(1, line.length() - 2);
}

std::string Mere::Config::Parser::GroupParser::subgroup(const std::string &group) const
{
    auto pos = group.find_last_of(m_spec.group()->delimiter());
    return group.substr(pos + 1);
}

std::string Mere::Config::Parser::GroupParser::parent(const std::string &group) const
{
    auto pos2 = group.find_last_of(m_spec.group()->delimiter());
    if (pos2 == std::string::npos)
        return "";

    auto pos1 = group.find_last_of(m_spec.group()->delimiter(), pos2 - 1);
    if (pos1 == std::string::npos)
        pos1 = -1;

    return group.substr(pos1 + 1, pos2 - pos1 -1 );
}

std::string Mere::Config::Parser::GroupParser::base(const std::string &group) const
{
    auto pos = group.find_last_of(m_spec.group()->delimiter());
    if (pos == std::string::npos)
        return "";

    return group.substr(0, pos);
}
