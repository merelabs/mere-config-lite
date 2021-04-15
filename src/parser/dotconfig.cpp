#include "dotconfig.h"

Mere::Config::Parser::DotConfig::DotConfig(const std::string &path)
    : Config(path)
{
    property().pattern("^\\\w+(\\\.\\\w)+=.*$");
}

