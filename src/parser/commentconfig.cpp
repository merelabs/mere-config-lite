#include "commentconfig.h"

#include <regex>

Mere::Config::Parser::CommentConfig::CommentConfig()
    : CommentConfig("^#.*")
{

}

Mere::Config::Parser::CommentConfig::CommentConfig(const std::string &pattern)
    : m_pattern(pattern)
{

}

std::string Mere::Config::Parser::CommentConfig::pattern() const
{
    return m_pattern;
}

void Mere::Config::Parser::CommentConfig::pattern(const std::string &pattern)
{
    m_pattern = pattern;
}

bool Mere::Config::Parser::CommentConfig::isComment(const std::string &line) const
{
    // make sure m_propertyt is a valid regex while setting it!
    const std::regex regex(m_pattern);

    return std::regex_match(line, regex);
}


