#ifndef DOCUMENT_H
#define DOCUMENT_H

#include "baseex.h"

namespace Mere
{
namespace Config
{
namespace Spec
{

class Document : public BaseEx
{
public:
    virtual ~Document();
    explicit Document(const std::string &path);

};

}
}
}
#endif // DOCUMENT_H
