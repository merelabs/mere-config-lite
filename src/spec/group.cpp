#include "group.h"

#include <regex>

Mere::Config::Spec::Group::~Group()
{

}

Mere::Config::Spec::Group::Group()
    : Group("^\\[(\\w+(\\/\\w+)*)\\]$")
{
}

Mere::Config::Spec::Group::Group(const std::string &pattern)
    : Domain(pattern),
      m_delimiter("/")
{
}

std::string Mere::Config::Spec::Group::delimiter() const
{
    return m_delimiter;
}

void Mere::Config::Spec::Group::delimiter(const std::string &delimiter)
{
    m_delimiter = delimiter;
}

bool Mere::Config::Spec::Group::isGroup(const std::string &line) const
{
    return valid(line);
}

bool Mere::Config::Spec::Group::isSubGroup(const std::string &line) const
{
    if (m_delimiter.empty()) return false;

    return isGroup(line) && line.find(delimiter()) != std::string::npos;
}

std::string Mere::Config::Spec::Group::name(const std::string &line) const
{
    return line.substr(1, line.length() - 2);
}

std::string Mere::Config::Spec::Group::subgroup(const std::string &group) const
{
    auto pos = group.find_last_of(delimiter());
    return group.substr(pos + 1);
}

std::string Mere::Config::Spec::Group::parent(const std::string &group) const
{
    auto pos2 = group.find_last_of(delimiter());
    if (pos2 == std::string::npos)
        return "";

    auto pos1 = group.find_last_of(delimiter(), pos2 - 1);
    if (pos1 == std::string::npos)
        pos1 = -1;

    return group.substr(pos1 + 1, pos2 - pos1 -1 );
}

std::string Mere::Config::Spec::Group::base(const std::string &group) const
{
    auto pos = group.find_last_of(delimiter());
    if (pos == std::string::npos)
        return "";

    return group.substr(0, pos);
}
