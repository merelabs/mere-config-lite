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
    std::vector<Property> parse(const std::string &section, int *set = nullptr) const;
    std::string parse(const std::string &section, const std::string &property, int *set = nullptr) const;

protected:
    bool isGroup(const std::string &line) const override;
    std::string group(const std::string &line) const override;

signals:

private:
    const GroupConfig &m_config;
};
}
}

#endif // SECTIONPARSER_H
