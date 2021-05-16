#ifndef MERE_CONFIG_ROOT_H
#define MERE_CONFIG_ROOT_H

#include "group.h"

namespace Mere
{
namespace Config
{

class MERE_CONFIG_LIB_SPEC RootGroup : public Group
{
public:
    ~RootGroup() = default;
    RootGroup() = default;

    bool valid() const override;

};

}
}
#endif // MERE_CONFIG_ROOT_H
