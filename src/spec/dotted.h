#ifndef MERE_CONFIG_SPEC_DOTTED_H
#define MERE_CONFIG_SPEC_DOTTED_H

#include "base.h"

namespace Mere
{
namespace Config
{
namespace Spec
{

class Dotted : public Base
{
public:
    virtual ~Dotted();
    explicit Dotted(const std::string &path);
};

}
}
}
#endif // MERE_CONFIG_SPEC_DOTTED_H
