#include "key.h"

Mere::Config::Spec::Key::~Key()
{

}

Mere::Config::Spec::Key::Key()
    : Key("^\\\w+")
{

}

Mere::Config::Spec::Key::Key(const std::string &pattern)
    : Domain(pattern)
{

}

bool Mere::Config::Spec::Key::isKey(const std::string &line) const
{
    return valid(line);
}

