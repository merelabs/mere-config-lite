#ifndef GKPARSER_H
#define GKPARSER_H

#include "groupparser.h"
#include "groupconfig.h"
#include "../property.h"

namespace Mere
{
namespace Config
{
namespace Parser
{

class MERE_CONFIG_LIB_SPEC GKParser : public GroupParser
{
public:
    explicit GKParser(const GroupConfig &config);

    virtual std::vector<Group> parse() const override;
    virtual Group parse(const std::string &name, int *set = nullptr) const override;
    virtual Property parse(const std::string &group, const std::string &property, int *set = nullptr) const override;

private:
    const GroupConfig &m_config;
};

}
}
}

#endif // GKPARSER_H
