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
    explicit GroupConfig(const std::string &path);
    explicit GroupConfig(const std::string &path, const std::string &type);

    //
    // in-memory query
    // call load before any of the query
    //

    // get the all the keys of all the groups and subgroups recursively
    // It will traverse all the groups and subgroups recursively and get the keys.
    // note: keys inside a group are listed as key = group/key
    virtual std::vector<std::string> getAllKeys() const = 0;

    // get the all the keys of a group with specified name
    // if the specified group name is not present, return empty property.
    // if 'set' flag specified, it will set the value of 'set' as
    // 0 - group with specified name is not present
    // 1 - otherwise
    virtual std::vector<std::string> getKeys(const std::string &name, int *set = nullptr) const = 0;

    // get all the keys of a group and its subgroups ( recursively )
    // It will traverse all the groups and subgroups recursively and get the properties.
    // keys inside a group are listed as key = group/key
    // if the specified group name is not present, return empty property.
    // if 'set' flag specified, it will set the value of 'set' as
    // 0 - group with specified name is not present
    // 1 - otherwise
    virtual std::vector<std::string> getAllKeys(const std::string &group, int *set = nullptr) const = 0;

    virtual Group* getGroup(const std::string &name) const = 0;

    // get of all groups
    virtual std::vector<Group *> getGroups() const = 0;

    // get of all groups and their subgroups ( recursively )
    virtual std::vector<Group *> getAllGroups() const = 0;

    // get of all the subgroups a group with specified name
    // if the specified group name is not present, return empty property.
    // if 'set' flag specified, it will set the value of 'set' as
    // 0 - group with specified name is not present
    // 1 - otherwise
    virtual std::vector<Group *> getGroups(const std::string &name, int *set = nullptr) const = 0;

    // get of all groups and subgroups of a group ( recursively )
    // if the specified group name is not present, return empty property.
    // if 'set' flag specified, it will set the value of 'set' as
    // 0 - group with specified name is not present
    // 1 - otherwise
    virtual std::vector<Group *> getAllGroups(const std::string &name, int *set = nullptr) const = 0;

    // get value of a key/flatten-key
    //std::string getValue(const std::string &key, int *set = nullptr) const;

    // get value of a key of a group with specified name
    // if the specified group name or property key is not present, return empty string.
    // if 'set' flag specified, it will set the value of 'set' as
    // 0 - group name or property with specified key is not present
    // 1 - otherwise
    virtual std::string getValue(const std::string &name, const std::string &key, int *set = nullptr) const = 0;

    virtual std::string getValue(const Group *group, const std::string &key, int *set = nullptr) const = 0;

    // get property associated with specified key of a group with specified name
    // if the specified group name or property key is not present, return empty property.
    // if 'set' flag specified, it will set the value of 'set' as
    // 0 - group name or property with specified key is not present
    // 1 - otherwise
    virtual Property* getProperty(const std::string &name, const std::string &key) const = 0;

    //get all the parent level properties
    //virtual std::vector<Property> getProperties() const = 0;

    // get all the properties of groups and subgroups ( recursively )
    // It will traverse all the groups and subgroups recursively and get the properties.
    // note: keys inside a group are listed as key = group/key
    virtual std::vector<Property *> getAllProperties() const = 0;

    // get all the properties of groups specified with name
    // if the specified group name or property key is not present, return empty list.
    // if 'set' flag specified, it will set the value of 'set' as
    // 0 - group name or property with specified key is not present
    // 1 - otherwise
    virtual std::vector<Property *> getProperties(const std::string &name, int *set = nullptr) const = 0;

    // get the all the properties of a group with specified name recursively from persistence system
    // It will traverse all the subgroup recursively and get the properties.
    // if the specified group name is not present, return empty property.
    // if 'set' flag specified, it will set the value of 'set' as
    // 0 - group with specified name is not present
    // 1 - otherwise
    virtual std::vector<Property *> getAllProperties(const std::string &name, int *set = nullptr) const = 0;

    // Online APIs
    // read all the parent level groups from persistence system
    //virtual std::vector<Group *> readGroups() const = 0;

    // read the group with the specified name from persistence system
    // if the specified group name is not present, return empty group.
    // if 'set' flag specified, it will set the value of 'set' as
    // 0 - group with specified name is not present
    // 1 - otherwise
    // if you already read the configuration, use 'get' for the value
    virtual Group* readGroup(const std::string &name) const = 0;

    //std::vector<Property> readProperties() const = 0;

    // read the all the properties of all the groups and subgroups recursively
    // It will traverse all the groups and subgroups recursively and get the properties.
    //virtual std::vector<Property *> readAllProperties() const = 0;

    // read the all the properties of a group with specified name from persistence system
    // if the specified group name is not present, return empty property.
    // if 'set' flag specified, it will set the value of 'set' as
    // 0 - group with specified name is not present
    // 1 - otherwise
    // if you already read the configuration, use 'get' for the value
    //virtual std::vector<Property *> readProperties(const std::string &name, int *set = nullptr) const = 0;

    // read the all the properties of a group with specified name recursively from persistence system
    // It will traverse all the subgroup recursively and read the properties.
    // if the specified group name is not present, return empty property.
    // if 'set' flag specified, it will set the value of 'set' as
    // 0 - group with specified name is not present
    // 1 - otherwise
    // if you already read the configuration, use 'get' for the value
    //virtual std::vector<Property *> readAllProperties(const std::string &name, int *set = nullptr) const = 0;

    // read the property associated with the specified key and group name from persistence system
    // if the specified group name or property key is not present, return empty property.
    // if 'set' flag specified, it will set the value of 'set' as
    // 0 - group name or property with specified key is not present
    // 1 - otherwise
    // if you already read the configuration, use 'get' for the value
    virtual Property* readProperty(const std::string &name, const std::string &key) const = 0;
};

}
}

#endif // MERE_CONFIG_GROUPCONFIG_H
