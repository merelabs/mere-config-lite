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

    // Offline APIs
    // list of all keys of current context
    virtual std::vector<std::string> getKeys() const = 0;

    // get value of a key
    virtual std::string getValue(const std::string &key, int *set = nullptr) const = 0;

    // alias of value
    virtual Property getProperty(const std::string &key, int *set = nullptr) const = 0;

    // get all key value pairs
    virtual std::vector<Property> getProperties() const = 0;

    // write
    virtual void setProperty(const Property &property) = 0;
    virtual void setValue(const std::string &key, const std::string &value) = 0;

    // Online APIs
    // read all the properties as key-value pair from the config file
    // if you already read it, use get for the property value
    virtual std::vector<Property> readProperties() const = 0;

    // read a property value from the config (.conf) file.
    // if you already read the config file, use get for the value
    virtual Property readProperty(const std::string &key, int *set = nullptr) const = 0;

    // write
    virtual int writeProperty(const std::string &name, const std::string &value) const = 0;
};

}
}
#endif // MERE_CONFIG_PROPERTYCONFIG_H
