#include "dotconfig.h"
#include "dotparser.h"

Mere::Config::DotConfig::DotConfig(const std::string &path, QObject *parent)
    : GroupConfig(path, ".ini", parent)
{
    load();
}

void Mere::Config::DotConfig::load()
{
    m_properties = this->properties();
}


std::vector<Mere::Config::Property> Mere::Config::DotConfig::properties() const
{
    DotParser parser(*this);
    return parser.parse();
}

bool Mere::Config::DotConfig::isGroup(const std::string &line) const
{
    auto pos = line.find("=");
    if (pos == std::string::npos)
        return false;

    auto dot = line.find(".");
    if (dot == std::string::npos)
        return false;

    if (dot > pos)
        return false;

    return true;
}
