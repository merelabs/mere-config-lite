#ifndef MERECONFIG_H
#define MERECONFIG_H

#include "global.h"

#include <QDebug>
#include <QObject>
#include <QSettings>

class MereSettings;

namespace Mere
{
namespace ConfigLite
{

class MERE_CONFIG_LITE_LIB_SPEC Config : public QObject
{
    Q_OBJECT
public:
    virtual ~Config();
    explicit Config(QObject *parent = 0);
    explicit Config(const std::string &path, QObject *parent = 0);
    explicit Config(const std::string &path, const std::string &type, QObject *parent = 0);

    QVariant get(const std::string &key) const;
    void set(const std::string &key, const QVariant &value);

    QVariant property(const std::string &property) const;
    std::map<std::string, QVariant> properties() const;

protected:
    void load();

private:
    std::string m_path;
    std::string m_type;
    QSettings *m_settings;

    std::map<std::string, QVariant> m_properties;
};

}
}


#endif // MERECONFIG_H
