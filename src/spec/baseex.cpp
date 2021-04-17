#include "baseex.h"

Mere::Config::Spec::BaseEx::~BaseEx()
{
    if(m_group)
    {
        delete m_group;
        m_group = nullptr;
    }
}

Mere::Config::Spec::BaseEx::BaseEx(const std::string &path)
    : Base(path),
      m_group(new Group)
{
}

Mere::Config::Spec::Group* Mere::Config::Spec::BaseEx::group() const
{
    return m_group;
}

void Mere::Config::Spec::BaseEx::group(Group *group)
{
    if(m_group)
        delete m_group;

    m_group = group;
}

bool Mere::Config::Spec::BaseEx::isGroup(const std::string &line) const
{
    return m_group->isGroup(line);
}
