#ifndef MERE_CONFIG_CROSSCONFIG_H
#define MERE_CONFIG_PARSER_VALUE_H

#include "groupconfig.h"

namespace Mere
{
namespace Config
{

class MERE_CONFIG_LIB_SPEC CrossConfig : public GroupConfig
{
public:
    virtual ~CrossConfig();
    explicit CrossConfig(const std::string &path);
    explicit CrossConfig(const std::string &path, const std::string &type);
};

}
}

#endif // MERE_CONFIG_PARSER_VALUE_H
