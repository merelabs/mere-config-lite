#include "config.h"

#include <regex>

Mere::Config::Parser::Config::~Config()
{
}

Mere::Config::Parser::Config::Config(const std::string &path)
    : m_path(path),
      m_strict(false)
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

Mere::Config::Parser::CommentConfig Mere::Config::Parser::Config::comment() const
{
    return m_comment;
}

void Mere::Config::Parser::Config::comment(const CommentConfig &comment)
{
    m_comment = comment;
}

bool Mere::Config::Parser::Config::isComment(const std::string &line) const
{
    return m_comment.isComment(line);
}
