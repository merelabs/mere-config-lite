#include "crossconfig.h"

Mere::Config::CrossConfig::~CrossConfig()
{

}

Mere::Config::CrossConfig::CrossConfig(const std::string &path, QObject *parent)
    : CrossConfig(path, ".conf", parent)
{
}

Mere::Config::CrossConfig::CrossConfig(const std::string &path, const std::string &type, QObject *parent)
    : GroupConfig(path, type, parent)
{
}
