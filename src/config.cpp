#include "config.h"
#include "pathresolver.h"

Mere::ConfigLite::Config::~Config()
{

}


Mere::ConfigLite::Config::Config(const std::string &path, QObject *parent)
    : Config(path, ".conf", parent)
{
}

Mere::ConfigLite::Config::Config(const std::string &path, const std::string &type, QObject *parent)
    : QObject(parent),
      m_path(path),
      m_type(type),
      m_settings(nullptr)
{
    PathResolver resolver;
    QString fqpath = resolver.resolve(QString::fromStdString(m_path), QString::fromStdString(m_type));

    m_settings = new QSettings(fqpath, QSettings::Format::IniFormat);
}

void Mere::ConfigLite::Config::load()
{
    m_properties = this->properties();
}

QVariant Mere::ConfigLite::Config::get(const std::string &key) const
{
    auto result = m_properties.find(key);
    if (result != m_properties.end())
        return result->second;

    return QVariant();
}

void Mere::ConfigLite::Config::set(const std::string &key, const QVariant &value)
{
    m_properties.insert({key, value});
}

QVariant Mere::ConfigLite::Config::property(const std::string &property) const
{
    QString prop(QString::fromStdString(property));

    if (m_settings->contains(prop))
        return m_settings->value(prop);

    return QVariant();
}

std::map<std::string, QVariant> Mere::ConfigLite::Config::properties() const
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
