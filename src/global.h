#ifndef MERE_CONFIG_GLOBAL_H
#define MERE_CONFIG_GLOBAL_H

#include <QtCore/QtGlobal>
#include <QDebug>

#if defined(MERE_CONFIG_LIB)
# define MERE_CONFIG_LIB_SPEC Q_DECL_EXPORT
#else
# define MERE_CONFIG_LIB_SPEC Q_DECL_IMPORT
#endif


#endif // MERE_CONFIG_GLOBAL_H
