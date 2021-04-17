#ifndef MERE_CONFIG_SPEC_DOMAIN_H
#define MERE_CONFIG_SPEC_DOMAIN_H

#include "../global.h"

namespace Mere
{
namespace Config
{

namespace Spec
{

class MERE_CONFIG_LIB_SPEC Domain
{
public:
    virtual ~Domain();
    Domain();
    Domain(const std::string &pattern);

    std::string pattern() const;
    void pattern(const std::string &pattern);

    virtual bool valid(const std::string &line) const;

private:
    std::string m_pattern;
};

}
}
}
#endif // MERE_CONFIG_SPEC_DOMAIN_H
