#ifndef PATHRESOLVER_H
#define PATHRESOLVER_H

#include <QObject>

namespace Mere
{
namespace ConfigLite
{

class PathResolver : public QObject
{
    Q_OBJECT
public:
    explicit PathResolver(QObject *parent = nullptr);
    QString resolve(const QString &path, const QString &type);

signals:

};

}
}

#endif // PATHRESOLVER_H
