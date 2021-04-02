#ifndef DOTCONFIG_H
#define DOTCONFIG_H

#include "groupconfig.h"

namespace Mere
{
namespace Config
{

class MERE_CONFIG_LIB_SPEC DotConfig : public GroupConfig
{
    Q_OBJECT
public:
    explicit DotConfig(const std::string &path, QObject *parent = nullptr);

protected:
    void load() override;

signals:

};

}
}
#endif // DOTCONFIG_H
