#ifndef MERE_CONFIG_SPEC_GROUP_H
#define MERE_CONFIG_SPEC_GROUP_H

#include "../global.h"
#include "domain.h"

namespace Mere
{
namespace Config
{
namespace Spec
{

class MERE_CONFIG_LIB_SPEC Group : public Domain
{
public:
    virtual ~Group();
    Group();
    Group(const std::string &pattern);

    Group(const Group &that) = default;
    Group& operator=(const Group &that) = default;
    Group(Group &&that) = default;
    Group& operator=(Group &&that) = default;

    std::string delimiter() const;
    void delimiter(const std::string &delimiter);

    bool isGroup(const std::string &line) const;
    bool isSubGroup(const std::string &line) const;

    std::string name(const std::string &line) const;
    std::string subgroup(const std::string &group) const;
    std::string parent(const std::string &group) const;
    std::string base(const std::string &group) const;

private:
    std::string m_delimiter;
    std::string m_subgroup;

};

}
}
}

#endif // MERE_CONFIG_SPEC_GROUP_H
