#ifndef MERE_CONFIG_PARSER_EXCONFIG_H
#define MERE_CONFIG_PARSER_EXCONFIG_H

#include "base.h"
#include "group.h"

namespace Mere
{
namespace Config
{
namespace Spec
{

class MERE_CONFIG_LIB_SPEC BaseEx : public Base
{
public:
    virtual ~BaseEx();
    explicit BaseEx(const std::string &path);

    Group* group() const;
    void group(Group *group);
    bool isGroup(const std::string &line) const;

private:
    Group *m_group;
};

}
}
}
#endif // MERE_CONFIG_PARSER_EXCONFIG_H
