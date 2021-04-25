#include "value.h"

Mere::Config::Spec::Value::~Value()
{

}

Mere::Config::Spec::Value::Value()
    : Value(".*")
{
}

Mere::Config::Spec::Value::Value(const std::string &pattern)
    : Domain(pattern)
{

}

bool Mere::Config::Spec::Value::isValue(const std::string &line) const
{
    return valid(line);
}
