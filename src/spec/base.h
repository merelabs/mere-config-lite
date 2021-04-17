#ifndef MERE_CONFIG_PARSER_CONFIG_H
#define MERE_CONFIG_PARSER_CONFIG_H

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

    std::string path() const;
    void path(const std::string &path);

    bool strict() const;
    void strict(bool strict);

    Comment* comment() const;
    void comment(Comment *comment);
    bool isComment(const std::string &line) const;

    Property* property() const;
    void property(Property *property);
    bool isProperty(const std::string &line) const;

private:
    std::string m_path;

    bool m_strict;

    Comment *m_comment;
    Property *m_property;
};

}
}
}


#endif // MERE_CONFIG_PARSER_CONFIG_H
