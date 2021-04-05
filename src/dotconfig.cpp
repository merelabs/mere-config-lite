#include "dotconfig.h"
#include "dotparser.h"

#include <QDebug>
Mere::Config::DotConfig::DotConfig(const std::string &path, QObject *parent)
    : GroupConfig(path, ".ini", parent)
{
//    load();
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

//bool Mere::Config::DotConfig::isGroup(const std::string &line) const
//{
//    auto pos = line.find('=');
//    if (pos == std::string::npos)
//        return false;

//    auto dot = line.find('.');
//    if (dot == std::string::npos)
//        return false;

//    if (dot > pos)
//        return false;

//    return true;
//}

//std::string Mere::Config::DotConfig::group(const std::string &line) const
//{
//    if (!isGroup(line)) return "";

//    auto pos = line.find('=');
//    if (pos == std::string::npos)
//        return "";

//    auto dot = line.rfind(".", pos);
//    if (dot == std::string::npos)
//        return "";

//    qDebug() << "LINE:" << line.c_str();
//    qDebug() << "GROUP:" << line.substr(0, dot).c_str();

//    return line.substr(0, dot);
//}
