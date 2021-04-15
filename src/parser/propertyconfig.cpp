#include "propertyconfig.h"

#include <regex>

Mere::Config::Parser::PropertyConfig::PropertyConfig()
    : PropertyConfig("^([\\\w._]+)=(.*)$")
{

}

Mere::Config::Parser::PropertyConfig::PropertyConfig(const std::string &pattern)
    : m_delimiter("="),
      m_pattern(pattern)
{

}

std::string Mere::Config::Parser::PropertyConfig::delimiter() const
{
    return m_delimiter;
}

void Mere::Config::Parser::PropertyConfig::delimiter(const std::string &delimiter)
{
    m_delimiter = delimiter;
}

std::string Mere::Config::Parser::PropertyConfig::pattern() const
{
    return m_pattern;
}

void Mere::Config::Parser::PropertyConfig::pattern(const std::string &property)
{
    m_pattern = property;
}

bool Mere::Config::Parser::PropertyConfig::isProperty(const std::string &line) const
{
    const std::regex regex(m_pattern);

    return std::regex_match(line, regex);
}
