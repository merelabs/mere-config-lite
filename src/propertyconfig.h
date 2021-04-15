#ifndef MERE_CONFIG_PROPERTYCONFIG_H
#define MERE_CONFIG_PROPERTYCONFIG_H

#include "config.h"
#include "property.h"

namespace Mere
{
namespace Config
{

class MERE_CONFIG_LIB_SPEC PropertyConfig : public Config
{
public:
    virtual ~PropertyConfig();
    explicit PropertyConfig(const std::string &path);
    explicit PropertyConfig(const std::string &path, const std::string &type);

    //
    // in-memory query
    // call load before any of the query
    //

    // list of all keys
    virtual std::vector<std::string> getKeys() const = 0;

    // get the value of fully qualified key's value
    // if the specified property key is not present, return empty string.
    // if 'set' flag specified, it will set the value of 'set' as
    // 0 - property with specified key is not present
    // 1 - otherwise
    virtual std::string getValue(const std::string &key, int *set = nullptr) const = 0;

    // get the property associated with the specified key
    // if the specified property key is not present, return empty property.
    // if 'set' flag specified, it will set the value of 'set' as
    // 0 - property with specified key is not present
    // 1 - otherwise
    virtual Property* getProperty(const std::string &key) const = 0;

    // get all properties
    virtual std::vector<Property *> getProperties() const = 0;

    // set the property
    // if the peoperty with specified key is not present, add one othewise
    // update the value of the property associated with the specified key
    virtual void setProperty(Property *property) = 0;

    // set the value for a fully qualified key
    // if the specified property key is not present, it will add one othewise
    // update the value of the property associated with the specified key
    virtual void setValue(const std::string &key, const std::string &value) = 0;

    // Online APIs
    // read all the properties from the  persistence system
    // if you already read it, use 'get' for the property value
    virtual std::vector<Property *> readProperties() const = 0;

    // read the property associated with the specified key from persistence system
    // if the specified property key is not present, return empty property.
    // if 'set' flag specified, it will set the value of 'set' as
    // 0 - property with specified key is not present
    // 1 - otherwise
    // if you already read the configuration, use 'get' for the value
    virtual Property* readProperty(const std::string &key) const = 0;

    // write
    //virtual int writeProperty(const std::string &name, const std::string &value) const = 0;
};

}
}
#endif // MERE_CONFIG_PROPERTYCONFIG_H
