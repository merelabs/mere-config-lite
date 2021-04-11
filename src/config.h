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

    std::string path() const;
    std::string type() const;

    // get value of fully qualified key's value
    virtual std::string get(const std::string &key, int *set = nullptr) const = 0;

    // set value for a fully qualified key
    virtual void set(const std::string &key, const std::string &value) = 0;

    // read value of fully qualified key's value
    virtual std::string read(const std::string &key, int *set = nullptr) const = 0;

    // write value for a fully qualified key
    virtual void write(const std::string &key, const std::string &value) = 0;

private:
    std::string m_path;
    std::string m_type;
};

}
}

#endif // MERE_CONFIG_CONFIG_H
