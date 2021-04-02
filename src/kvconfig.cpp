#include "kvconfig.h"
#include "kvparser.h"

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
    : Config(path, type, parent)
{
}

void Mere::Config::KVConfig::load()
{
    m_config = this->properties();
}

std::string Mere::Config::KVConfig::get(const std::string &key, int *set) const
{
    auto result = m_config.find(key);
    if (result != m_config.end())
    {
        if (set) *set = 1;
        return result->second;
    }

    if (set) *set = 0;

    return "";
}

void Mere::Config::KVConfig::set(const std::string &key, const std::string &value)
{
    m_config.insert({key, value});
}

std::string Mere::Config::KVConfig::property(const std::string &property, int *set) const
{
    KVParser parser(*this);
    return parser.parse(property, set);
}

std::map<std::string, std::string> Mere::Config::KVConfig::properties() const
{
    KVParser parser(*this);
    return parser.parse();
}
