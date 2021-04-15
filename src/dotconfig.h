#ifndef MERE_CONFIG_DOTCONFIG_H
#define MERE_CONFIG_DOTCONFIG_H

#include "groupconfig.h"
#include "parser/dotconfig.h"

namespace Mere
{
namespace Config
{

class MERE_CONFIG_LIB_SPEC DotConfig : public PropertyConfig
{
public:
    explicit DotConfig(const std::string &path);

    // config
    std::string get(const std::string &fqkp, int *set = nullptr) const override;
    void set(const std::string &fqkp, const std::string &value) override;
    std::string read(const std::string &fqkp, int *set = nullptr) const override;

//    // property config
    std::vector<std::string> getKeys() const override;
    std::string getValue(const std::string &key, int *set = nullptr) const override;
    Property* getProperty(const std::string &key) const override;
    std::vector<Property *> getProperties() const override;
    void setProperty(Property *property) override;
    void setValue(const std::string &key, const std::string &value) override;
    std::vector<Property *> readProperties() const override;
    Property* readProperty(const std::string &key) const override;

//    // group config
    std::vector<std::string> getKeys(const std::string &name, int *set = nullptr) const;
    std::vector<std::string> getAllKeys(const std::string &name, int *set = nullptr) const;
    std::vector<Property *> getProperties(const std::string &name, int *set = nullptr) const;
    std::vector<Property *> getAllProperties(const std::string &name, int *set = nullptr) const;

private:
    void load();

signals:

private:
    std::vector<Mere::Config::Property *> m_properties;

    Mere::Config::Parser::DotConfig m_config;
};

}
}
#endif // MERE_CONFIG_DOTCONFIG_H
