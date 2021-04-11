#include "groupconfig.h"

Mere::Config::GroupConfig::~GroupConfig()
{

}

Mere::Config::GroupConfig::GroupConfig(const std::string &path, QObject *parent)
    : GroupConfig(path, ".conf", parent)
{
}

Mere::Config::GroupConfig::GroupConfig(const std::string &path, const std::string &type, QObject *parent)
    : PropertyConfig(path, type, parent)
{
}
