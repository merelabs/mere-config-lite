#include "dotconfig.h"
#include "dotparser.h"

Mere::Config::DotConfig::DotConfig(const std::string &path, QObject *parent)
    : GroupConfig(path, ".ini", parent)
{
    load();
}

void Mere::Config::DotConfig::load()
{
//    DotParser parser(path(), *this);

//    parser.parse();
}
