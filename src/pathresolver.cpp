#include "pathresolver.h"

#include <QDebug>
#include <QFile>

Mere::ConfigLite::PathResolver::PathResolver(QObject *parent) : QObject(parent)
{

}

QString Mere::ConfigLite::PathResolver::resolve(const QString &path, const QString &type)
{
    if (path.startsWith("/"))
        return path;

    qDebug() << path << type;

    // check in /usr/local/etc
    QString local("/usr/local/etc/");
    local = local.append(path);

    if(QFile(local).exists()) return local;

    // chck in /etc
    QString system("/etc/");
    system = system.append(path);
    if(QFile(system).exists()) return system;


    return "";
}
