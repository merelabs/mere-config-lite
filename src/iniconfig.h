#ifndef MERE_CONFIG_INICONFIG_H
#define MERE_CONFIG_INICONFIG_H

#include "crossconfig.h"
#include "document.h"
#include "rootgroup.h"
#include "group.h"
#include "spec/document.h"

namespace Mere
{
namespace Config
{

class MERE_CONFIG_LIB_SPEC IniConfig : public CrossConfig
{
public:
    explicit IniConfig(const std::string &path);

    // config
    std::string get(const std::string &fqkp, bool *set = nullptr) const override;
    void set(const std::string &fqkp, const std::string &value) override;
    std::string read(const std::string &fqkp, bool *set = nullptr) const override;

    // property config
    std::vector<std::string> getKeys() const override;
    std::string getValue(const std::string &key, bool *set = nullptr) const override;
    Property* getProperty(const std::string &key) const override;
    std::vector<Property *> getProperties() const override;
    void setProperty(Property *property) override;
    void setValue(const std::string &key, const std::string &value) override;
    std::vector<Property *> readProperties() const override;
    Property* readProperty(const std::string &key) const override;

    // group config
    std::vector<std::string> getAllKeys() const override;
    std::vector<std::string> getKeys(const std::string &name, bool *set = nullptr) const override;
    std::vector<std::string> getAllKeys(const std::string &group, bool *set = nullptr) const override;
    Group* getGroup(const std::string &name) const override;
    std::vector<Group *> getGroups() const override;
    std::vector<Group *> getAllGroups() const override;
    std::vector<Group *> getGroups(const std::string &name, bool *set = nullptr) const override;
    std::vector<Group *> getAllGroups(const std::string &name, bool *set = nullptr) const override;

    std::string getValue(const std::string &name, const std::string &key, bool *set = nullptr) const override;
    std::string getValue(const Group *group, const std::string &key, bool *set = nullptr) const override;
    Property* getProperty(const std::string &name, const std::string &key) const override;

    std::vector<Property *> getAllProperties() const override;
    std::vector<Property *> getProperties(const std::string &name, bool *set = nullptr) const override;
    std::vector<Property *> getAllProperties(const std::string &name, bool *set = nullptr) const override;

    Document* readDocument() const;
    Group* readGroup(const std::string &name) const override;
    Property* readProperty(const std::string &name, const std::string &key) const override;

    //
    void load();

private:
    Document *m_document;

    Mere::Config::Spec::Document m_config;
};

}
}

#endif // MERE_CONFIG_INICONFIG_H
