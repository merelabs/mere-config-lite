#include "kvconfig.h"
#include "parser.h"
#include "pathresolver.h"

#include <fstream>
#include <iostream>

Mere::Config::KVConfig::~KVConfig()
{

}

Mere::Config::KVConfig::KVConfig(const std::string &path, QObject *parent)
    : KVConfig(path, ".conf", parent)
{
}

Mere::Config::KVConfig::KVConfig(const std::string &path, const std::string &type, QObject *parent)
    : QObject(parent),
      m_path(path),
      m_type(type)
{
    PathResolver resolver;
    std::string fqpath = resolver.resolve(m_path, m_type);
}

void Mere::Config::KVConfig::load()
{
    m_properties = this->properties();
}

std::string Mere::Config::KVConfig::get(const std::string &key, int *set) const
{
    auto result = m_properties.find(key);
    if (result != m_properties.end())
    {
        if (set) *set = 1;
        return result->second;
    }

    if (set) *set = 0;

    return "";
}

void Mere::Config::KVConfig::set(const std::string &key, const std::string &value)
{
    m_properties.insert({key, value});
}

std::string Mere::Config::KVConfig::property(const std::string &property, int *set) const
{
    Parser parser(m_path);
    return parser.parse(property, set);
}

std::map<std::string, std::string> Mere::Config::KVConfig::properties() const
{
    Parser parser(m_path);
    return parser.parse();
}

bool Mere::Config::KVConfig::comment(const std::string &line) const
{
    auto pos = line.find("#");

    return pos == 0;
}

std::string Mere::Config::KVConfig::key(const std::string &line) const
{
    auto pos = line.find("=");
    if (pos == 0 || pos == std::string::npos) return "";

    return line.substr(0, pos);
}

std::string Mere::Config::KVConfig::value(const std::string &line) const
{
    auto pos = line.find("=");
    if (pos == 0 || pos == std::string::npos) return "";

    return line.substr(pos + 1);
}
