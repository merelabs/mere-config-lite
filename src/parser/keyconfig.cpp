#include "keyconfig.h"

Mere::Config::Parser::KeyConfig::KeyConfig()
    : KeyConfig("^\\\w+")
{

}

Mere::Config::Parser::KeyConfig::KeyConfig(const std::string &pattern)
    : m_pattern(pattern)
{

}

std::string Mere::Config::Parser::KeyConfig::pattern() const
{
    return m_pattern;
}

void Mere::Config::Parser::KeyConfig::pattern(const std::string &pattern)
{
    m_pattern = pattern;
}

