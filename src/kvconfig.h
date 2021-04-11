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
    Q_OBJECT
public:
    virtual ~KVConfig();
    explicit KVConfig(const std::string &path, QObject *parent = 0);
    explicit KVConfig(const std::string &path, const std::string &type, QObject *parent = 0);

    virtual std::string get(const std::string &key, int *set = nullptr) const override;
    virtual void set(const std::string &key, const std::string &value) override;

    virtual std::string read(const std::string &key, int *set = nullptr) const override;
    //virtual void write(const std::string &key, const std::string &value) override;


    //
    // in-memory query
    // call load before any of the query
    //

    // Offline APIs
    // flat list of all keys
    // keys inside a secion are listed as
    // key = section/key
    virtual std::vector<std::string> getKeys() const override;

    // get value of a key/flatten-key
    virtual std::string getValue(const std::string &key, int *set = nullptr) const override;

    // alias of value
    virtual Property getProperty(const std::string &key, int *set = nullptr) const override;

    // get all key value pairs
    virtual std::vector<Property> getProperties() const override;

    // write
    virtual void setProperty(const Property &property) override;
    virtual void setValue(const std::string &key, const std::string &value) override;

    //
    // in-persistence query
    //

    // Online APIs
    // read all the properties as key-value pair from the config (.conf) file
    // if you already read it, use get for the property value
    virtual std::vector<Property> readProperties() const override;

    // read a property value from the config (.conf) file.
    // if you already read the config file, use get for the value
    virtual Property readProperty(const std::string &key, int *set = nullptr) const override;

    // write
    //virtual int writeProperty(const std::string &name, const std::string &value) const;

    void load();

private:
    std::vector<Mere::Config::Property> m_properties;
};

}
}

#endif // MERE_CONFIG_KVCONFIG_H
