#ifndef COMMENTCONFIG_H
#define COMMENTCONFIG_H

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
    Comment();
    explicit Comment(const std::string &pattern);
    bool isComment(const std::string &line) const;
};

}
}
}
#endif // COMMENTCONFIG_H
