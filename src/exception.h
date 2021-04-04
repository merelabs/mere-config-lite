#ifndef EXCEPTION_H
#define EXCEPTION_H

#include "global.h"
#include <string>

namespace Mere
{
namespace Config
{

class MERE_CONFIG_LIB_SPEC Exception : public std::exception
{
public:
    explicit Exception(const std::string& message);
    const char* what() const noexcept override;

private:
    std::string m_message;
};

}
}

#endif // EXCEPTION_H
