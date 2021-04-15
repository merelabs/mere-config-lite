#include "valueconfig.h"

Mere::Config::Parser::ValueConfig::ValueConfig()
{

}

std::string Mere::Config::Parser::ValueConfig::pattern() const
{
    return m_pattern;
}

void Mere::Config::Parser::ValueConfig::pattern(const std::string &pattern)
{
    m_pattern = pattern;
}

