#ifndef __CITANIA_H_
#define __CITANIA_H_

#include "breviar.h"
#include "mysystem.h"
#include "mysysdef.h"

#ifdef IO_ANDROID
char *StringEncode(const char *in, bool query_string = false);
char *toUtf(const char *in);
#endif

#ifdef LITURGICKE_CITANIA_ANDROID

struct citanie {
  const char *kod, *citania, *zalm, *aleluja;
};

struct citanie *najdiCitanie(const char *kod);
char *getCode(_struct_dm *d);

#endif // LITURGICKE_CITANIA_ANDROID

#endif // __CITANIA_H_
