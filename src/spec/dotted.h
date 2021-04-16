#ifndef DOTTED_H
#define DOTTED_H

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
#endif // DOTTED_H
