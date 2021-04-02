#ifndef SECTIONPARSER_H
#define SECTIONPARSER_H

#include "groupconfig.h"
#include "groupparser.h"

namespace Mere
{
namespace Config
{

class IniParser : public GroupParser
{
    Q_OBJECT
public:
    explicit IniParser(const GroupConfig &config, QObject *parent = nullptr);
    std::vector<Group> parse() const;

private:
    bool isGroup(const std::string &line) const;

signals:

private:
    const GroupConfig &m_config;
};
}
}

#endif // SECTIONPARSER_H
