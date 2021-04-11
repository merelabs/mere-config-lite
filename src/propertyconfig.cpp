#include "propertyconfig.h"

Mere::Config::PropertyConfig::~PropertyConfig()
{
}

Mere::Config::PropertyConfig::PropertyConfig(const std::string &path)
    : PropertyConfig(path, ".conf")
{
}

Mere::Config::PropertyConfig::PropertyConfig(const std::string &path, const std::string &type)
    : Config(path, type)
{
}
