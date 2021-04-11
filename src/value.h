#ifndef VALUE_H
#define VALUE_H

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

#endif // VALUE_H
