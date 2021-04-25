#include "exception.h"

Mere::Config::Exception::Exception(const std::string& message)
    : m_message(message)
{

}

const char* Mere::Config::Exception::what() const throw()
{
    return m_message.c_str();
}
