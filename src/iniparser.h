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
    std::map<std::string, std::map<std::string, std::string>> parse() const;

    bool section(const std::string &line) const;

signals:

private:

};
}
}

#endif // SECTIONPARSER_H
