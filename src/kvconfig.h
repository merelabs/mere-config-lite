#ifndef MERE_CONFIG_KVCONFIG_H
#define MERE_CONFIG_KVCONFIG_H

#include "global.h"

#include <QObject>
#include <QSettings>

class MereSettings;

namespace Mere
{
namespace Config
{

class MERE_CONFIG_LIB_SPEC KVConfig : public QObject
{
    Q_OBJECT
public:
    virtual ~KVConfig();
    explicit KVConfig(QObject *parent = 0);
    explicit KVConfig(const std::string &path, QObject *parent = 0);
    explicit KVConfig(const std::string &path, const std::string &type, QObject *parent = 0);

    QVariant get(const std::string &key) const;
    void set(const std::string &key, const QVariant &value);

    QVariant property(const std::string &property) const;
    std::map<std::string, QVariant> properties() const;

protected:
    virtual void load();

private:
    bool m_loaded;
    std::string m_path;
    std::string m_type;
    QSettings *m_settings;

    std::map<std::string, QVariant> m_properties;
};

}
}


#endif // MERE_CONFIG_KVCONFIG_H
