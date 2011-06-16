#include "citania.h"
#include "liturgia.h"
#include <string.h>
#include <stdlib.h>

static struct citanie Citania[] = {
#include "citania-gen.cpp"
  { NULL, NULL, NULL, NULL }
};

static int nc = -1;

static int cmpcitanie(const void *a, const void *b) {
  return strcmp(((struct citanie *)a)->kod, ((struct citanie *)b)->kod);
}

struct citanie *najdiCitanie(const char *kod) {
  struct citanie *c;
  if (nc ==-1) {
    for (nc=0; Citania[nc].kod; nc++);
  }
  c = (citanie *)bsearch(kod, Citania, nc, sizeof(struct citanie), cmpcitanie);
  if (!c) return NULL;
  if (!c->citania[0]) return NULL;
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
  return buf;
}

