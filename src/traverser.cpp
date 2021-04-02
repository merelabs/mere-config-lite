#include "traverser.h"

Mere::Config::Traverser::Traverser(const std::string &path, const Config &config, QObject *parent)
    : QObject(parent),
      m_path(path),
      m_config(config)
{

}
