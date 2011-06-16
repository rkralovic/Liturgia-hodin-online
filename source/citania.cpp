#include "citania.h"
#include "liturgia.h"
#include <string.h>
#include <stdlib.h>

#include <android/log.h>

static struct citanie Citania[] = {
#include "citania-gen.cpp"
  { NULL, NULL, NULL, NULL }
};

static int nc = -1;

static int cmpcitanie(const void *a, const void *b) {
  return strcmp((const char *)a, ((struct citanie *)b)->kod);
}

struct citanie *najdiCitanie(const char *kod) {
  struct citanie *c;
  __android_log_print(ANDROID_LOG_INFO, "Breviar", "called najdiCitanie");
  __android_log_print(ANDROID_LOG_INFO, "Breviar", kod);
  if (nc == -1) {
    __android_log_print(ANDROID_LOG_INFO, "Breviar", "init");
    for (nc=0; Citania[nc].kod; nc++);
    __android_log_print(ANDROID_LOG_INFO, "Breviar", "init done");
  }
  __android_log_print(ANDROID_LOG_INFO, "Breviar", "bsearch");
  c = (citanie *)bsearch(kod, Citania, nc, sizeof(struct citanie), cmpcitanie);
  __android_log_print(ANDROID_LOG_INFO, "Breviar", "bsearch done");
  if (!c) return NULL;
  __android_log_print(ANDROID_LOG_INFO, "Breviar", "c not null");
  if (!c->citania[0]) return NULL;
  __android_log_print(ANDROID_LOG_INFO, "Breviar", "known");
  return c;
};

static char nedelnyCyklus(_struct_dm *d) {
  return 'A' + nedelny_cyklus(d->den, d->mesiac, d->rok);
}

static char ferialnyCyklus(_struct_dm *d) {
  return '1' + ferialny_cyklus(d->den, d->mesiac, d->rok);
}

char *getCode(_struct_dm *d) {
  static char buf[100];

  __android_log_print(ANDROID_LOG_INFO, "Breviar", "called getcode");
  if (d->smer == 1) { sprintf(buf, "%02d%02d%d", d->smer, d->litobd, d->denvt); // Velkonocne trojdnie
  } else if (d->smer == 2) { // niektore maju nedelny cyklus, niektore nie (Popolcova streda).
    if (d->meno[0]) {        // zatial dame pismeno cyklu vzdy; neublizi to.
      sprintf(buf, "%02d%c%s", d->smer, nedelnyCyklus(d), remove_diacritics(d->meno));
    } else {
      sprintf(buf, "%02d%c%02d%02d%02d", d->smer, nedelnyCyklus(d), d->litobd, d->tyzden, d->denvt);
    }
  } else if (d->smer <= 5) {
    sprintf(buf, "%02d%c%s", d->smer, nedelnyCyklus(d), remove_diacritics(d->meno));
  } else if (d->smer == 6) { // nedele vianocneho a cezrocneho obdobia
    sprintf(buf, "%02d%c%02d%02d", d->smer, nedelnyCyklus(d), d->litobd, d->tyzden);
  } else if (d->smer <= 8) {
    sprintf(buf, "%02d%s", d->smer, remove_diacritics(d->meno));
  } else if (d->smer <= 9) {
    if (d->smer == 9 && d->mesiac == 12 && d->den <=24) { // na konci adventu rozhoduje kalendarny datum
      sprintf(buf, "%02d%02d%02d", d->smer, d->litobd, d->den);
    } else {
      sprintf(buf, "%02d%c%02d%02d%02d", d->smer, ferialnyCyklus(d), d->litobd, d->tyzden, d->denvt);
    }
  } else if (d->smer <= 12) {
    sprintf(buf, "%02d%s", d->smer, remove_diacritics(d->meno));
  } else {
    sprintf(buf, "%02d%c%02d%02d%02d", d->smer, ferialnyCyklus(d), d->litobd, d->tyzden, d->denvt);
  }
  __android_log_print(ANDROID_LOG_INFO, "Breviar", buf);
  return buf;
}

char *StringEncode(const char *in) {
  static unsigned char tab[17]="0123456789ABCDEF";
  int i;
  const char *s;
  static char out[65536];

  __android_log_print(ANDROID_LOG_INFO, "Breviar", "encode called");
  for (s=(const char *)in,i=0; i<sizeof(out)-5 && *s; s++) {
    if (
        ( (*s>='a')&&(*s<='z') ) ||
        ( (*s>='A')&&(*s<='Z') ) ||
        ( (*s>='0')&&(*s<='9') )
       ) {
      out[i]=*s;
      i+=1;
    } else {
      out[i]='%';
      out[i+1]=tab[(*s) >> 4];
      out[i+2]=tab[(*s) & 0xf];
      i+=3;
    }
  }
  out[i]=0;
  return out;
}
