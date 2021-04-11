#include "config.h"

#include <regex>

Mere::Config::Parser::Config::~Config()
{

}

Mere::Config::Parser::Config::Config(const std::string &path)
    : m_path(path),
      m_strict(false),
      m_comment("^#.*")
{

}

std::string Mere::Config::Parser::Config::path() const
{
    return m_path;
}

void Mere::Config::Parser::Config::path(const std::string &path)
{
    m_path = path;
}

bool Mere::Config::Parser::Config::strict() const
{
    return m_strict;
}

void Mere::Config::Parser::Config::strict(bool strict)
{
    m_strict = strict;
}

std::string Mere::Config::Parser::Config::comment() const
{
    return m_comment;
}

void Mere::Config::Parser::Config::comment(const std::string &commnet)
{
    m_comment = commnet;
}

bool Mere::Config::Parser::Config::isComment(const std::string &line) const
{
    // make sure m_comment is a valid regex while setting it!
    const std::regex regex(m_comment);

    return std::regex_match(line, regex);
}
