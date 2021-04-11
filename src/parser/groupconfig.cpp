#include "groupconfig.h"

#include <regex>

Mere::Config::Parser::GroupConfig::GroupConfig(const std::string &path)
    : PropertyConfig(path),
      m_delimiter("/"),
      m_group("^\\\[(\\\w+(\\/\\\w+)*)\\\]$")
{

}

std::string Mere::Config::Parser::GroupConfig::delimiter() const
{
    return m_delimiter;
}

void Mere::Config::Parser::GroupConfig::delimiter(const std::string &delimiter)
{
    m_delimiter = delimiter;
}

std::string Mere::Config::Parser::GroupConfig::group() const
{
    return m_group;
}

void Mere::Config::Parser::GroupConfig::group(const std::string &group)
{
    m_group = group;
}

bool Mere::Config::Parser::GroupConfig::isGroup(const std::string &line) const
{
    // make sure m_propertyt is a valid regex while setting it!
    const std::regex regex(m_group);

    return std::regex_match(line, regex);
}

bool Mere::Config::Parser::GroupConfig::isSubGroup(const std::string &line) const
{
    return isGroup(line) && line.find(delimiter()) != std::string::npos;
}

std::string Mere::Config::Parser::GroupConfig::group(const std::string &line) const
{
    return line.substr(1, line.length() - 2);
}

std::string Mere::Config::Parser::GroupConfig::subgroup(const std::string &group) const
{
    auto pos = group.find_last_of(delimiter());
    return group.substr(pos + 1);
}

std::string Mere::Config::Parser::GroupConfig::parent(const std::string &group) const
{
    auto pos2 = group.find_last_of(delimiter());
    if (pos2 == std::string::npos)
        return "";

    auto pos1 = group.find_last_of(delimiter(), pos2 - 1);
    if (pos1 == std::string::npos)
        pos1 = -1;

    return group.substr(pos1 + 1, pos2 - pos1 -1 );
}

std::string Mere::Config::Parser::GroupConfig::base(const std::string &group) const
{
    auto pos = group.find_last_of(delimiter());
    if (pos == std::string::npos)
        return "";

    return group.substr(0, pos);
}
