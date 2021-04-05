#ifndef MERE_CONFIG_GROUPPARSER_H
#define MERE_CONFIG_GROUPPARSER_H

#include "groupconfig.h"
#include "parser.h"
#include "group.h"

namespace Mere
{
namespace Config
{

class MERE_CONFIG_LIB_SPEC GroupParser : public Parser
{
    Q_OBJECT
public:
    explicit GroupParser(const GroupConfig &config, QObject *parent = nullptr);

    virtual bool isGroup(const std::string &line) const = 0;
    virtual std::string group(const std::string &line) const = 0;

    virtual std::vector<Property> parse(const std::string &group, int *set = nullptr) const = 0;
    virtual std::string parse(const std::string &group, const std::string &property, int *set = nullptr) const = 0;
};

}
}

#endif // MERE_CONFIG_GROUPPARSER_H
