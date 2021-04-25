#ifndef MERE_CONFIG_SPEC_KEY_H
#define MERE_CONFIG_SPEC_KEY_H

#include "../global.h"
#include "domain.h"

namespace Mere
{
namespace Config
{
namespace Spec
{

class MERE_CONFIG_LIB_SPEC Key : public Domain
{
public:
    virtual ~Key();
    Key();

    Key(const Key &that) = default;
    Key& operator=(const Key &that) = default;
    Key(Key &&that) = default;
    Key& operator=(Key &&that) = default;

    explicit Key(const std::string &pattern);
    bool isKey(const std::string &line) const;
};

}
}
}

#endif // MERE_CONFIG_SPEC_KEY_H
