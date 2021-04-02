#ifndef CONFIGTRAVERSER_H
#define CONFIGTRAVERSER_H

#include <QObject>

class ConfigTraverser : public QObject
{
    Q_OBJECT
public:
    explicit ConfigTraverser(QObject *parent = nullptr);

signals:

};

#endif // CONFIGTRAVERSER_H
