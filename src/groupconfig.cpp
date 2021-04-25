#include "groupconfig.h"

Mere::Config::GroupConfig::~GroupConfig()
{

}

Mere::Config::GroupConfig::GroupConfig(const std::string &path)
    : GroupConfig(path, ".conf")
{
}

Mere::Config::GroupConfig::GroupConfig(const std::string &path, const std::string &type)
    : PropertyConfig(path, type)
{
}
