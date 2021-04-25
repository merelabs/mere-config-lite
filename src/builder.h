#ifndef CONFIGBUILDER_H
#define CONFIGBUILDER_H

#include <QObject>

class Builder : public QObject
{
    Q_OBJECT
public:
    explicit Builder(const std::string &path, QObject *parent = nullptr);
    explicit Builder(const std::string &path, const std::string &type, QObject *parent = 0);

    Builder& path() const;
    Builder& type() const;

signals:

};

#endif // CONFIGBUILDER_H
