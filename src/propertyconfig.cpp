#include "propertyconfig.h"

Mere::Config::PropertyConfig::~PropertyConfig()
{
}

Mere::Config::PropertyConfig::PropertyConfig(const std::string &path, const Spec::Strict &strict)
    : PropertyConfig(path, ".conf", strict)
{
}

Mere::Config::PropertyConfig::PropertyConfig(const std::string &path, const std::string &type, const Spec::Strict &strict)
    : Config(path, type, strict)
{
}
