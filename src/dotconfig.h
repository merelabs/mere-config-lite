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

//    //
//    // in-memory query
//    // call load before any of the query
//    //

//    // flat list of all keys
//    // keys inside a secion are listed as
//    // key = section/key
    std::vector<std::string> keys() const override;

//    // list of all keys of a section
    std::vector<std::string> keys(const std::string &group, int *set = nullptr) const override;

    // list of all keys of a section
    //std::vector<std::string> keys(const Group &group, int *set = nullptr) const;

//    // list of all sections
//    std::vector<std::string> sections() const;

//    // list of all sections of a section
//    std::vector<std::string> sections(const std::string &section, int *set = nullptr) const;

//    // get value of a key/flatten-key
    std::string value(const std::string &key, int *set = nullptr) const override;

//    // get value of a key of a section
    std::string value(const std::string &group, const std::string &key, int *set = nullptr) const;
//    std::string value(const Group &group, const std::string &key, int *set = nullptr) const;

//    // alias of value
    Property get(const std::string &key) const;
    std::string get(const std::string &key, int *set = nullptr) const override;
    std::string get(const std::string &group, const std::string &key, int *set = nullptr) const;

    std::map<std::string, std::string> mget() const;
    std::map<std::string, std::string> mget(const std::string &group, int *set = nullptr) const;
//    std::map<std::string, std::string> mget(const Group &group) const;

    //
    // sync query - query directly to the config file
    //
    //std::vector<Group> groups() const override;
    //Group group(const std::string &name, int *set = nullptr) const override;

    std::vector<Property> properties() const override;
    std::vector<Property> properties(const std::string &group, int *set = nullptr) const override;
    //std::vector<Property> properties(const Group &group, int *set = nullptr) const override;
    virtual Property property(const std::string &group, const std::string &key, int *set = nullptr) const;
    //virtual Property property(const std::string &name, int *set = nullptr) const = 0;

    virtual bool isGroup(const std::string &line) const override;
    virtual std::string name(const std::string &line) const;

private:
    void load();

signals:

private:
    std::vector<Mere::Config::Property> m_properties;
};

}
}
#endif // DOTCONFIG_H
