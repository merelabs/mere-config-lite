#include "config.h"
#include "pathresolver.h"

Mere::Config::Config::~Config()
{
}

Mere::Config::Config::Config(const std::string &path, const Spec::Strict &strict)
    : Config(path, ".dot", strict)
{
}

Mere::Config::Config::Config(const std::string &path, const std::string &type, const Spec::Strict &strict)
    : m_type(type),
      m_strict(strict)
{
    PathResolver resolver;
    m_path = resolver.resolve(path, type);
}

std::string Mere::Config::Config::path() const
{
    return m_path;
}

std::string Mere::Config::Config::type() const
{
    return m_type;
}

Mere::Config::Spec::Strict Mere::Config::Config::strict() const
{
    return m_strict;
}
