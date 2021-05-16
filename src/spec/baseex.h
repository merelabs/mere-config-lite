#ifndef MERE_CONFIG_SPEC_BASEEXCONFIG_H
#define MERE_CONFIG_SPEC_BASEEXCONFIG_H

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

    BaseEx(const BaseEx &that)
        : Base(that),
          m_group(that.m_group ? new Group(*that.m_group) : nullptr)
    {
    };

    BaseEx& operator=(const BaseEx &that)
    {
//        Base::operator=(that);
        BaseEx copy{that};
        swap(*this, copy);

        return *this;
    };

    BaseEx(BaseEx &&that) = default;
    BaseEx& operator=(BaseEx &&that) = default;

    friend void swap(BaseEx &lhs, BaseEx &rhs)
    {
        using std::swap;
        swap(static_cast<Base&>(lhs), static_cast<Base&>(rhs));
        swap(lhs.m_group   , rhs.m_group);
    }

    Group* group() const;
    void group(Group *group);
    bool isGroup(const std::string &line) const;

private:
    Group *m_group;
};

}
}
}
#endif // MERE_CONFIG_SPEC_BASEEXCONFIG_H
