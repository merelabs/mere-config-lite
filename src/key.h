#ifndef MERE_CONFIG_KEY_H
#define MERE_CONFIG_KEY_H

#include <QObject>

namespace Mere
{
namespace Config
{

class Key : public QObject
{
    Q_OBJECT
public:
    explicit Key(QObject *parent = nullptr);

signals:

};

}
}

#endif // MERE_CONFIG_KEY_H
