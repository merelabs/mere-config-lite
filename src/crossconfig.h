#ifndef CROSSCONFIG_H
#define CROSSCONFIG_H

#include "groupconfig.h"

namespace Mere
{
namespace Config
{

class MERE_CONFIG_LIB_SPEC CrossConfig : public GroupConfig
{
public:
    virtual ~CrossConfig();
    explicit CrossConfig(const std::string &path, QObject *parent = 0);
    explicit CrossConfig(const std::string &path, const std::string &type, QObject *parent = 0);
};

}
}

#endif // CROSSCONFIG_H
