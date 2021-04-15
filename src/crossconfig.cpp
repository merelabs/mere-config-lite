#include "crossconfig.h"

Mere::Config::CrossConfig::~CrossConfig()
{

}

Mere::Config::CrossConfig::CrossConfig(const std::string &path)
    : CrossConfig(path, ".conf")
{
}

Mere::Config::CrossConfig::CrossConfig(const std::string &path, const std::string &type)
    : GroupConfig(path, type)
{
}
