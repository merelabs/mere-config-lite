#ifndef WRITER_H
#define WRITER_H

#include <QObject>

namespace Mere
{
namespace Config
{

class Writer : public QObject
{
    Q_OBJECT
public:
    explicit Writer(QObject *parent = nullptr);

signals:

};

}
}

#endif // WRITER_H
