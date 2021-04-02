#include "config.h"
#include "pathresolver.h"

Mere::Config::Config::~Config()
{

}

Mere::Config::Config::Config(const std::string &path, QObject *parent)
    : Config(path, ".dot", parent)
{

}

Mere::Config::Config::Config(const std::string &path, const std::string &type, QObject *parent)
    : QObject(parent),
      m_path(path),
      m_type(type)
{
    PathResolver resolver;
    std::string fqpath = resolver.resolve(path, type);

}

std::string Mere::Config::Config::path() const
{
    return m_path;
}

bool Mere::Config::Config::isCommnet(const std::string &line) const
{
    return line.front() == '#';
}
