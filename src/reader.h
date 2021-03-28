#ifndef READER_H
#define READER_H

#include <QObject>

namespace Mere
{
namespace Config
{

class Reader : public QObject
{
    Q_OBJECT
public:
    explicit Reader(QObject *parent = nullptr);

signals:

};

}
}

#endif // READER_H
