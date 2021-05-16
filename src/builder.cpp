#include "builder.h"

Builder::Builder(const std::string &path, QObject *parent) : QObject(parent)
{
    Q_UNUSED(path)
}

Builder::Builder(const std::string &path, const std::string &type, QObject *parent) : QObject(parent)
{
    Q_UNUSED(path)
    Q_UNUSED(type)
}
