#include "config.h"

#include <regex>

Mere::Config::Parser::Config::~Config()
{
    if (m_comment)
    {
        delete m_comment;
        m_comment = nullptr;
    }

    if (m_property)
    {
        delete m_property;
        m_property = nullptr;
    }
}

Mere::Config::Parser::Config::Config(const std::string &path)
    : m_path(path),
      m_strict(false),
      m_comment(new CommentConfig),
      m_property(new PropertyConfig)
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

Mere::Config::Parser::CommentConfig *Mere::Config::Parser::Config::comment() const
{
    return m_comment;
}

void Mere::Config::Parser::Config::comment(CommentConfig *comment)
{
    m_comment = comment;
}

bool Mere::Config::Parser::Config::isComment(const std::string &line) const
{
    return m_comment->isComment(line);
}

Mere::Config::Parser::PropertyConfig* Mere::Config::Parser::Config::property() const
{
    return m_property;
}

void Mere::Config::Parser::Config::property(PropertyConfig *property)
{
    m_property = property;
}

bool Mere::Config::Parser::Config::isProperty(const std::string &line) const
{
    return m_property->isProperty(line);
}
