#ifndef INICONFIG_H
#define INICONFIG_H

#include "crossconfig.h"
#include "document.h"
#include "rootgroup.h"
#include "group.h"

namespace Mere
{
namespace Config
{

class MERE_CONFIG_LIB_SPEC IniConfig : public CrossConfig
{
    Q_OBJECT
public:
    explicit IniConfig(const std::string &path, QObject *parent = nullptr);

    //
    // in-memory query
    // call load before any of the query
    //

    // flat list of all keys
    // keys inside a secion are listed as
    // key = group/key
    std::vector<std::string> getKeys() const override;
    std::vector<std::string> getAllKeys() const override;

    // list of all keys of a section
    std::vector<std::string> getKeys(const std::string &group, int *set = nullptr) const override;
    std::vector<std::string> getAllKeys(const std::string &group, int *set = nullptr) const override;

    // list of all keys of a section
    std::vector<std::string> getKeys(const Group &group) const override;

    // list of all groups
    std::vector<Group> getGroups() const override;
    std::vector<Group> getAllGroups() const override;

    // list of all groups of a group
    std::vector<Group> getGroups(const std::string &group, int *set = nullptr) const override;
    std::vector<Group> getAllGroups(const std::string &group, int *set = nullptr) const override;

    // retrieve the named group
    Group getGroup(const std::string &group, int *set = nullptr) const override;

    // get value of a key/flatten-key
    std::string getValue(const std::string &key, int *set = nullptr) const override;

    // get value of a key of a section
    std::string getValue(const std::string &group, const std::string &key, int *set = nullptr) const override;
    std::string getValue(const Group &group, const std::string &key, int *set = nullptr) const override;

    // get all key value pairs
    std::vector<Property> getProperties() const override;
    std::vector<Property> getAllProperties() const override;

    std::vector<Property> getProperties(const std::string &group, int *set = nullptr) const;
    std::vector<Property> getAllProperties(const std::string &group, int *set = nullptr) const;

    std::vector<Property> getProperties(const Group &group) const;
    std::vector<Property> getAllProperties(const Group &group) const;

    // Online APIs
    // read all the properties as key-value pair from the config (.conf) file
    // if you already read it, use get for the property value
    std::vector<Group> readGroups() const override;
    Group readGroup(const std::string &name, int *set = nullptr) const override;

    std::vector<Property> readProperties() const = 0;
    std::vector<Property> readAllProperties() const = 0;

    std::vector<Property> readProperties(const std::string &group, int *set = nullptr) const = 0;
    std::vector<Property> readAllProperties(const std::string &group, int *set = nullptr) const = 0;

    std::vector<Property> readProperties(const Group &group, int *set = nullptr) const = 0;
    std::vector<Property> readAllProperties(const Group &group, int *set = nullptr) const = 0;

    Property readProperty(const std::string &key, int *set = nullptr) const = 0;
    Property readProperty(const std::string &group, const std::string &key, int *set = nullptr) const = 0;
    Property readProperty(const Group &group, const std::string &key, int *set = nullptr) const = 0;


    Document readDocument() const;

    void load();

private:
    std::vector<Mere::Config::Property> getProperties(std::vector<Group> groups) const;

private:
    Group m_group;
    Document m_document;
};

}
}

#endif // INICONFIG_H
