#include "kvconfig.h"
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
    std::string value;

    if (set) *set = 0;

    // check for the file extension
    std::string ext(".conf");
    auto pos = m_path.find(ext);
    if (pos != m_path.length() - ext.length())
        return "";

    std::ifstream file(m_path);

    // check for the file existance
    if (!file.good()) return "";

    std::string line;
    while (std::getline(file, line))
    {
        if (line.empty()) continue;
        if (this->comment(line)) continue;

        std::string key   = this->key(line);
        if (key != property) continue;

        if (set) *set = 1;
        value = this->value(line);
        break;
    }

    return value;
}

std::map<std::string, std::string> Mere::Config::KVConfig::properties() const
{
    std::map<std::string, std::string> properties;

    // check for the file extension
    std::string ext(".conf");
    auto pos = m_path.find(ext);
    if (pos != m_path.length() - ext.length())
        return properties;

    std::ifstream file(m_path);

    // check for the file existance
    if (!file.good()) return properties;

    std::string line;
    while (std::getline(file, line))
    {
        if (line.empty()) continue;
        if (this->comment(line)) continue;

        std::string key   = this->key(line);
        std::string value = this->value(line);

        properties.insert({key, value});
    }

    return properties;
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
