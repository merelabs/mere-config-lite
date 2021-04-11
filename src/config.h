#ifndef MERE_CONFIG_CONFIG_H
#define MERE_CONFIG_CONFIG_H

#include "global.h"

namespace Mere
{
namespace Config
{

class MERE_CONFIG_LIB_SPEC Config
{
    Q_OBJECT
public:
    virtual ~Config();
    explicit Config(const std::string &path);
    explicit Config(const std::string &path, const std::string &type);

    // get the absolute path of the configuration
    std::string path() const;

    // get the type of the configuration
    std::string type() const;

    // get the value of fully qualified key's value
    // if the specified property key is not present, return empty string.
    // if 'set' flag specified, it will set the value of 'set' as
    // 0 - property with specified key is not present
    // 1 - otherwise
    virtual std::string get(const std::string &key, int *set = nullptr) const = 0;

    // set the value for a fully qualified key
    // if the peoperty with specified key is not present, add one othewise
    // update the value of the property associated with the specified key
    virtual void set(const std::string &key, const std::string &value) = 0;

    // read the value of fully qualified key's value from persistence system
    // if the specified property key is not present, return empty string.
    // if 'set' flag specified, it will set the value of 'set' as
    // 0 - property with specified key is not present
    // 1 - otherwise
    virtual std::string read(const std::string &key, int *set = nullptr) const = 0;

    // write the value for a fully qualified key to the persistence system
    //virtual void write(const std::string &key, const std::string &value) = 0;

private:
    std::string m_path;
    std::string m_type;
};

}
}

#endif // MERE_CONFIG_CONFIG_H
