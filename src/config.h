#ifndef MERE_CONFIG_CONFIG_H
#define MERE_CONFIG_CONFIG_H

#include "global.h"
#include "spec/base.h"
namespace Mere
{
namespace Config
{

class MERE_CONFIG_LIB_SPEC Config
{
public:
    virtual ~Config();
    explicit Config(const std::string &path, const Spec::Strict &strict = Spec::Strict::None);
    explicit Config(const std::string &path, const std::string &type, const Spec::Strict &strict = Spec::Strict::None);

    // get the absolute path of the configuration
    std::string path() const;

    // get the type of the configuration
    std::string type() const;

    Spec::Strict strict() const;

    // get the value of fully qualified key's value
    // if the specified property key is not present, return empty string.
    // if 'set' flag specified, it will set the value of 'set' as
    // false - property with specified key is not present
    // true - otherwise
    virtual std::string get(const std::string &key, bool *set = nullptr) const = 0;

    // set the value for a fully qualified key
    // if the peoperty with specified key is not present, add one othewise
    // update the value of the property associated with the specified key
    virtual void set(const std::string &key, const std::string &value) = 0;

    // read the value of fully qualified key's value from persistence system
    // if the specified property key is not present, return empty string.
    // if 'set' flag specified, it will set the value of 'set' as
    // false - property with specified key is not present
    // true - otherwise
    virtual std::string read(const std::string &key, bool *set = nullptr) const = 0;

    // write the value for a fully qualified key to the persistence system
    //virtual void write(const std::string &key, const std::string &value) = 0;

private:
    std::string  m_path;
    std::string  m_type;
    Spec::Strict m_strict;
};

}
}

#endif // MERE_CONFIG_CONFIG_H
