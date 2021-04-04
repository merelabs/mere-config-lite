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

    std::vector<Mere::Config::Property> properties() const;

    virtual bool isGroup(const std::string &line) const override;

private:
    void load();

signals:

private:
    std::vector<Mere::Config::Property> m_properties;
};

}
}
#endif // DOTCONFIG_H
