#include "kvconfig.h"
#include "pathresolver.h"

Mere::Config::KVConfig::~KVConfig()
{
    if (m_settings)
    {
        delete m_settings;
        m_settings = nullptr;
    }
}


Mere::Config::KVConfig::KVConfig(const std::string &path, QObject *parent)
    : KVConfig(path, ".conf", parent)
{
}

Mere::Config::KVConfig::KVConfig(const std::string &path, const std::string &type, QObject *parent)
    : QObject(parent),
      m_loaded(false),
      m_path(path),
      m_type(type),
      m_settings(nullptr)
{
    PathResolver resolver;
    std::string fqpath = resolver.resolve(m_path, m_type);

    m_settings = new QSettings(QString::fromStdString(fqpath), QSettings::Format::IniFormat);
}

void Mere::Config::KVConfig::load()
{
    m_properties = this->properties();
    m_loaded = true;
}

QVariant Mere::Config::KVConfig::get(const std::string &key) const
{
    auto result = m_properties.find(key);
    if (result != m_properties.end())
        return result->second;

    return QVariant();
}

void Mere::Config::KVConfig::set(const std::string &key, const QVariant &value)
{
    m_properties.insert({key, value});
}

QVariant Mere::Config::KVConfig::property(const std::string &property) const
{
    QString prop(QString::fromStdString(property));

    if (m_settings->contains(prop))
        return m_settings->value(prop);

    return QVariant();
}

std::map<std::string, QVariant> Mere::Config::KVConfig::properties() const
{
    std::map<std::string, QVariant> properties;

    QStringList keys = m_settings->allKeys();
    for(QString key : keys)
    {
        QVariant value = m_settings->value(key);
        properties.insert({key.toStdString(), value});
    }

    return properties;
}
