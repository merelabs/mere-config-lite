#include "domain.h"

#include <regex>

Mere::Config::Spec::Domain::~Domain()
{

}

Mere::Config::Spec::Domain::Domain()
    : Domain("^.*$")
{

}

Mere::Config::Spec::Domain::Domain(const std::string &pattern)
    : m_pattern(pattern)
{

}

std::string Mere::Config::Spec::Domain::pattern() const
{
    return m_pattern;
}

void Mere::Config::Spec::Domain::pattern(const std::string &pattern)
{
    m_pattern = pattern;
}

bool Mere::Config::Spec::Domain::valid(const std::string &line) const
{
    const std::regex regex(m_pattern);

    return std::regex_match(line, regex);
}
