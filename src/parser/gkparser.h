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

    std::vector<Group *> parse() const override;
    Group* parse(const std::string &name, int *set = nullptr) const override;
    Property* parse(const std::string &name, const std::string &key, int *set = nullptr) const override;

protected:
    std::string group(const std::string &line) const;
    std::string subgroup(const std::string &group) const;
    std::string parent(const std::string &group) const;
    std::string base(const std::string &group) const;

private:
    const Spec::BaseEx &m_spec;

};

}
}
}
#endif // GKPARSER_H
