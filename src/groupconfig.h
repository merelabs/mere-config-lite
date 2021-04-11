#ifndef MERE_CONFIG_GROUPCONFIG_H
#define MERE_CONFIG_GROUPCONFIG_H

#include "propertyconfig.h"
#include "group.h"

namespace Mere
{
namespace Config
{

class MERE_CONFIG_LIB_SPEC GroupConfig : public PropertyConfig
{
public:
    virtual ~GroupConfig();
    explicit GroupConfig(const std::string &path, QObject *parent = 0);
    explicit GroupConfig(const std::string &path, const std::string &type, QObject *parent = 0);

    //
    // in-memory query
    // call load before any of the query
    //

    // list of all keys
    //std::vector<std::string> getKeys() const override;

    // keys inside a secion are listed as
    // key = group/key
    virtual std::vector<std::string> getAllKeys() const = 0;

    // list of all keys of a section
    virtual std::vector<std::string> getKeys(const std::string &group, int *set = nullptr) const = 0;
    virtual std::vector<std::string> getAllKeys(const std::string &group, int *set = nullptr) const = 0;

    // list of all keys of a section
    virtual std::vector<std::string> getKeys(const Group &group) const = 0;
    virtual std::vector<std::string> getAllKeys(const Group &group) const = 0;

    // list of all groups
    virtual std::vector<Group> getGroups() const = 0;
    virtual std::vector<Group> getAllGroups() const = 0;

    // list of all groups of a group
    virtual std::vector<Group> getGroups(const std::string &group, int *set = nullptr) const = 0;
    virtual std::vector<Group> getAllGroups(const std::string &group, int *set = nullptr) const = 0;

    // retrieve the named group
    virtual Group getGroup(const std::string &group, int *set = nullptr) const = 0;

    // get value of a key/flatten-key
    //std::string getValue(const std::string &key, int *set = nullptr) const;

    // get value of a key of a section
    virtual std::string getValue(const std::string &group, const std::string &key, int *set = nullptr) const = 0;
    virtual std::string getValue(const Group &group, const std::string &key, int *set = nullptr) const = 0;

    // alias of value
    virtual Property getProperty(const std::string &group, const std::string &key, int *set = nullptr) const = 0;


    // get all key value pairs
    //virtual std::vector<Property> getProperties() const = 0;
    virtual std::vector<Property> getAllProperties() const = 0;

    virtual std::vector<Property> getProperties(const std::string &group, int *set = nullptr) const = 0;
    virtual std::vector<Property> getAllProperties(const std::string &group, int *set = nullptr) const = 0;

    virtual std::vector<Property> getProperties(const Group &group) const = 0;
    virtual std::vector<Property> getAllProperties(const Group &group) const = 0;

    // Online APIs
    // read all the properties as key-value pair from the config (.conf) file
    // if you already read it, use get for the property value

    virtual std::vector<Group> readGroups() const = 0;
    virtual Group readGroup(const std::string &name, int *set = nullptr) const = 0;

    //std::vector<Property> readProperties() const = 0;
    std::vector<Property> readAllProperties() const = 0;

    virtual std::vector<Property> readProperties(const std::string &group, int *set = nullptr) const = 0;
    virtual std::vector<Property> readAllProperties(const std::string &group, int *set = nullptr) const = 0;

    virtual std::vector<Property> readProperties(const Group &group, int *set = nullptr) const = 0;
    virtual std::vector<Property> readAllProperties(const Group &group, int *set = nullptr) const = 0;

    //Property readProperty(const std::string &key, int *set = nullptr) const = 0;
    virtual Property readProperty(const std::string &group, const std::string &key, int *set = nullptr) const = 0;
    virtual Property readProperty(const Group &group, const std::string &key, int *set = nullptr) const = 0;
};

}
}

#endif // MERE_CONFIG_GROUPCONFIG_H
