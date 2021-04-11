#include "crossconfig.h"

Mere::Config::Parser::CrossConfig::CrossConfig(const std::string &path)
    : GroupConfig(path),
      m_delimiter("/"),
      m_group("^\\\[(\\\w+(\\/\\\w+)*)\\\]$")
{

}
