#include "base.h"

#include <regex>

Mere::Config::Spec::Base::~Base()
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

Mere::Config::Spec::Base::Base(const std::string &path)
    : m_path(path),
      m_strict(false),
      m_comment(new Comment),
      m_property(new Property)
{
}

std::string Mere::Config::Spec::Base::path() const
{
    return m_path;
}

void Mere::Config::Spec::Base::path(const std::string &path)
{
    m_path = path;
}

bool Mere::Config::Spec::Base::strict() const
{
    return m_strict;
}

void Mere::Config::Spec::Base::strict(bool strict)
{
    m_strict = strict;
}

Mere::Config::Spec::Comment *Mere::Config::Spec::Base::comment() const
{
    return m_comment;
}

void Mere::Config::Spec::Base::comment(Comment *comment)
{
    if (m_comment)
        delete m_comment;
    m_comment = comment;
}

bool Mere::Config::Spec::Base::isComment(const std::string &line) const
{
    return m_comment->isComment(line);
}

Mere::Config::Spec::Property* Mere::Config::Spec::Base::property() const
{
    return m_property;
}

void Mere::Config::Spec::Base::property(Property *property)
{
    if (m_property)
        delete m_property;

    m_property = property;
}

bool Mere::Config::Spec::Base::isProperty(const std::string &line) const
{
    return m_property->isProperty(line);
}
