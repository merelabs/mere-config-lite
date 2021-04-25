#ifndef MERE_CONFIG_SPEC_BASE_H
#define MERE_CONFIG_SPEC_BASE_H

#include "../global.h"
#include "comment.h"
#include "property.h"

#include <string>

namespace Mere
{
namespace Config
{
namespace Spec
{

class MERE_CONFIG_LIB_SPEC Base
{
public:
    virtual ~Base();
    explicit Base(const std::string &path);

    Base(const Base &that)
        : m_path(that.m_path),
          m_strict(that.m_strict),
          m_comment(that.m_comment ? new Comment(*that.m_comment) : nullptr),
          m_property(that.m_property ? new Property(*that.m_property) : nullptr)
    {
    };

    Base& operator=(const Base &that)
    {
        Base copy{that};
        swap(*this, copy);

        return *this;
    };

    Base(Base &&that) = default;
    Base& operator=(Base &&that) = default;

    friend void swap(Base &lhs, Base &rhs)
    {
      using std::swap;
      swap(lhs.m_path       , rhs.m_path);
      swap(lhs.m_strict     , rhs.m_strict);
      swap(lhs.m_comment    , rhs.m_comment);
      swap(lhs.m_property   , rhs.m_property);
    }


    std::string path() const;
    void path(const std::string &path);

    enum class Strict
    {
        None,
        Soft,
        Hard
    };

    Strict strict() const;
    void strict(Strict strict);

    Comment* comment() const;
    void comment(Comment *comment);
    bool isComment(const std::string &line) const;

    Property* property() const;
    void property(Property *property);
    bool isProperty(const std::string &line) const;

private:
    std::string m_path;

    Strict m_strict;

    Comment *m_comment;
    Property *m_property;
};

}
}
}


#endif // MERE_CONFIG_SPEC_BASE_H
