#include "config.h"
#include "pathresolver.h"

Mere::Config::Config::~Config()
{
}

Mere::Config::Config::Config(const std::string &path)
    : Config(path, ".dot")
{
}

Mere::Config::Config::Config(const std::string &path, const std::string &type)
    : m_type(type)
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
