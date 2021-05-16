#ifndef MERE_CONFIG_SPEC_COMMENTCONFIG_H
#define MERE_CONFIG_SPEC_COMMENTCONFIG_H

#include "../global.h"
#include "domain.h"

namespace Mere
{
namespace Config
{
namespace Spec
{

class MERE_CONFIG_LIB_SPEC Comment : public Domain
{
public:
    virtual ~Comment();
    Comment();

    Comment(const Comment &that) = default;
    Comment& operator=(const Comment &that) = default;
    Comment(Comment &&that) = default;
    Comment& operator=(Comment &&that) = default;

    explicit Comment(const std::string &pattern);
    bool isComment(const std::string &line) const;
};

}
}
}
#endif // MERE_CONFIG_SPEC_COMMENTCONFIG_H
