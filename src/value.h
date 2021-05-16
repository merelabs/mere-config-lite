#ifndef MERE_CONFIG_VALUE_H
#define MERE_CONFIG_VALUE_H

#include <QObject>

namespace Mere
{
namespace Config
{

class Value : public QObject
{
    Q_OBJECT
public:
    explicit Value(QObject *parent = nullptr);

//    int toInt();
//    bool toBool();

signals:

};

}
}

#endif // MERE_CONFIG_VALUE_H
