#include "propertyconfig.h"

#include <regex>

Mere::Config::Parser::PropertyConfig::PropertyConfig(const std::string &path)
    : Config(path),
      m_delimiter("="),
      m_property("^([\\\w._]+)=(.*)$")
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

std::string Mere::Config::Parser::PropertyConfig::property() const
{
    return m_property;
}

void Mere::Config::Parser::PropertyConfig::property(const std::string &property)
{
    m_property = property;
}

bool Mere::Config::Parser::PropertyConfig::isProperty(const std::string &line) const
{
    // make sure m_propertyt is a valid regex while setting it!
    const std::regex regex(m_property);

    return std::regex_match(line, regex);
}
