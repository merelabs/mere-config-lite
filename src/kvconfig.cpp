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
    m_properties = this->properties();
}

std::string Mere::Config::KVConfig::get(const std::string &key, int *set) const
{
    auto result = std::find_if(m_properties.begin(), m_properties.end(), [&](const Property &property){
        return property.name().compare(key) == 0;
    });

    if (result != m_properties.end())
    {
        if (set) *set = 1;
        return result->value();
    }

    if (set) *set = 0;

    return "";
}

void Mere::Config::KVConfig::set(const std::string &key, const std::string &value)
{
    m_properties.push_back(Property(key, value));
}


std::vector<Mere::Config::Property> Mere::Config::KVConfig::properties() const
{
    KVParser parser(*this);
    return parser.parse();
}
