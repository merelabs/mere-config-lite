#include "configex.h"

Mere::Config::Parser::ConfigEx::~ConfigEx()
{
    if(m_group)
    {
        delete m_group;
        m_group = nullptr;
    }
}

Mere::Config::Parser::ConfigEx::ConfigEx(const std::string &path)
    : Config(path),
      m_group(new GroupConfig)
{
}

Mere::Config::Parser::GroupConfig* Mere::Config::Parser::ConfigEx::group() const
{
    return m_group;
}

void Mere::Config::Parser::ConfigEx::group(GroupConfig *group)
{
    m_group = group;
}

bool Mere::Config::Parser::ConfigEx::isGroup(const std::string &line) const
{
    return m_group->isGroup(line);
}
