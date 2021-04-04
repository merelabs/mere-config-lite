#ifndef MERE_CONFIG_KVCONFIG_H
#define MERE_CONFIG_KVCONFIG_H

#include "config.h"
#include "property.h"

namespace Mere
{
namespace Config
{

class MERE_CONFIG_LIB_SPEC KVConfig : public Config
{
    Q_OBJECT
public:
    virtual ~KVConfig();
    explicit KVConfig(const std::string &path, QObject *parent = 0);
    explicit KVConfig(const std::string &path, const std::string &type, QObject *parent = 0);

    std::string get(const std::string &key, int *set = nullptr) const;
    void set(const std::string &key, const std::string &value);

    /**
     * @brief property
     * @param property
     * read a property value from the config (.conf) file.
     * if you already read the config file, use get for the value
     * @return
     */
    std::string property(const std::string &property, int *set = nullptr) const;

    /**
     * @brief properties
     * read all the properties as key-value pair from the config (.conf) file
     * if you already read it, use get for the property value
     * @return
     */
    std::vector<Mere::Config::Property> properties() const;

private:
    void load();

private:
    std::vector<Mere::Config::Property> m_properties;
};

}
}

#endif // MERE_CONFIG_KVCONFIG_H
