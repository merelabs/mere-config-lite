#ifndef MERE_CONFIG_KVCONFIG_H
#define MERE_CONFIG_KVCONFIG_H

#include "propertyconfig.h"
#include "property.h"

namespace Mere
{
namespace Config
{

class MERE_CONFIG_LIB_SPEC KVConfig : public PropertyConfig
{
public:
    virtual ~KVConfig();
    explicit KVConfig(const std::string &path);
    explicit KVConfig(const std::string &path, const std::string &type);

    virtual std::string get(const std::string &key, int *set = nullptr) const override;
    virtual void set(const std::string &key, const std::string &value) override;
    virtual std::string read(const std::string &key, int *set = nullptr) const override;

    virtual std::vector<std::string> getKeys() const override;
    virtual std::string getValue(const std::string &key, int *set = nullptr) const override;
    virtual Property* getProperty(const std::string &key) const override;
    virtual std::vector<Property *> getProperties() const override;

    virtual void setProperty(Property *property) override;
    virtual void setValue(const std::string &key, const std::string &value) override;

    virtual std::vector<Property *> readProperties() const override;
    virtual Property* readProperty(const std::string &key) const override;

    void load();

private:
    std::vector<Mere::Config::Property *> m_properties;
};

}
}

#endif // MERE_CONFIG_KVCONFIG_H
