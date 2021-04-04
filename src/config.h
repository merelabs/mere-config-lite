#ifndef CONFIG_H
#define CONFIG_H

#include "global.h"

#include <QObject>

namespace Mere
{
namespace Config
{

class MERE_CONFIG_LIB_SPEC Config : public QObject
{
    Q_OBJECT
public:
    virtual ~Config();
    explicit Config(const std::string &path, QObject *parent = 0);
    explicit Config(const std::string &path, const std::string &type, QObject *parent = 0);

    virtual std::string path() const;
//    virtual std::string get(const std::string &key, int *set) const = 0;
//    virtual void set(const std::string &key, const std::string &value) = 0;
    virtual bool isCommnet(const std::string &line) const;

protected:
//    virtual void load() = 0;

private:
    std::string m_path;
    std::string m_type;
};

}
}

#endif // CONFIG_H
