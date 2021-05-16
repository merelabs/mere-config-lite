#ifndef MERE_CONFIG_SPEC_DOCUMENT_H
#define MERE_CONFIG_SPEC_DOCUMENT_H

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
#endif // MERE_CONFIG_SPEC_DOCUMENT_H
