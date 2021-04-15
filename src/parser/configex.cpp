#include "configex.h"

Mere::Config::Parser::ConfigEx::ConfigEx(const std::string &path)
    : Config(path),
      m_group("^\\\[(\\\w+(\\/\\\w+)*)\\\]$")
{
//          m_delimiter("/"),
//          m_group()
}

Mere::Config::Parser::GroupConfig Mere::Config::Parser::ConfigEx::group() const
{
    return m_group;
}

void Mere::Config::Parser::ConfigEx::group(const GroupConfig &group)
{
    m_group = group;
}

bool Mere::Config::Parser::ConfigEx::isGroup(const std::string &line) const
{
    return m_group.isGroup(line);
}
