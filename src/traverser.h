#ifndef TRAVERSER_H
#define TRAVERSER_H

#include "config.h"

#include <QObject>

namespace Mere
{
namespace Config
{

class Traverser : public QObject
{
    Q_OBJECT
public:
    explicit Traverser(const std::string &path, const Config &config, QObject *parent = nullptr);

//    std::string next();
//    std::string prev();

//    iterrator;

signals:
private:
    const std::string m_path;
    const Config &m_config;
};

}
}

#endif // TRAVERSER_H
