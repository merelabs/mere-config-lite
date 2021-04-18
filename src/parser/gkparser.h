#ifndef GKPARSER_H
#define GKPARSER_H

#include "groupparser.h"

namespace Mere
{
namespace Config
{

namespace Parser
{


class MERE_CONFIG_LIB_SPEC GKParser : public GroupParser
{
public:
    explicit GKParser(const Spec::BaseEx &spec);

    std::vector<Group *> parseGroups() const override;
    Group* parseGroup(const std::string &name) const override;
    Property* parseProperty(const std::string &name, const std::string &key) const override;

private:
    Group *parent(Group *node, const std::string &parent) const;

private:
    const Spec::BaseEx &m_spec;

};

}
}
}
#endif // GKPARSER_H
