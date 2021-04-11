#include "dotconfig.h"

Mere::Config::Parser::DotConfig::DotConfig(const std::string &path)
    : PropertyConfig(path)
{
    delimiter("=");
    property("^\\\w+(\\\.\\\w)+=.*$");
}

