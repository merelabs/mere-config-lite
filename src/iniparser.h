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
    Group parse(const std::string &match) const;

protected:
    bool isGroup(const std::string &line) const override;

signals:

private:
    const GroupConfig &m_config;
};
}
}

#endif // SECTIONPARSER_H
