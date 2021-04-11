#include "document.h"

Mere::Config::Document::Document(const std::string &name)
    : m_name(name)
{

}

std::string Mere::Config::Document::name() const
{
    return m_name;
}

void Mere::Config::Document::name(const std::string &name)
{
    m_name = name;
}

Mere::Config::RootGroup Mere::Config::Document::root() const
{
    return m_root;
}

void Mere::Config::Document::root(const RootGroup &root)
{
    m_root = root;
}
