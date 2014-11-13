#ifndef __UTF8_UTILS_H_
#define __UTF8_UTILS_H_

inline int DecodeWchar(const char** s) {
  int output;
  int to_read;
  while (1) {
    if ((**s & 0x80) == 0) return *((*s)++);
    if ((**s & 0xe0) == 0xc0) {
      to_read = 1;
      output = *((*s)++) & 0x3f;
      break;
    }
    if ((**s & 0xf0) == 0xe0) {
      to_read = 2;
      output = *((*s)++) & 0x0f;
      break;
    }
    if ((**s & 0xf8) == 0xf0) {
      to_read = 3;
      output = *((*s)++) & 0x07;
      break;
    }
    (*s)++;
  }
  while (to_read-- > 0 && (**s & 0xc0) == 0x80) {
    output = (output << 6) | (*((*s)++) & 0x3f);
  }
  return output;
}

inline void EncodeWchar(int w, char** s) {
  if (w < 0x80) {
    *((*s)++) = w;
  } else if (w >= (1<<22)) {
    *((*s)++) = '?';
  } else {
    char buf[3];
    int len = 0;
    int pfx = 0x80;

    while (w >= (1 << (6 - len))) {
      pfx = 0x80 | (pfx >> 1);
      buf[len++] = (w & 0x3f) | 0x80;
      w = w >> 6;
    }
    *((*s)++) = pfx | w;
    while (len > 0) {
      *((*s)++) = buf[--len];
    }
  }
}

inline int WcharToUppercase(int w) {
  if (w >= 'a' && w <= 'z') {
    return w - 'a' + 'A';
  }
  switch (w) {
    case L'á': return L'Á';
    case L'ä': return L'Ä';
    case L'č': return L'Č';
    case L'ď': return L'Ď';
    case L'é': return L'É';
    case L'í': return L'Í';
    case L'ĺ': return L'Ĺ';
    case L'ľ': return L'Ľ';
    case L'ň': return L'Ň';
    case L'ó': return L'Ó';
    case L'ô': return L'Ô';
    case L'ö': return L'Ö';
    case L'ő': return L'Ő';
    case L'ŕ': return L'Ŕ';
    case L'ř': return L'Ř';
    case L'š': return L'Š';
    case L'ť': return L'Ť';
    case L'ú': return L'Ú';
    case L'ů': return L'Ů';
    case L'ü': return L'Ü';
    case L'ű': return L'Ű';
    case L'ý': return L'Ý';
    case L'ž': return L'Ž';
  }
  return w;
}

inline int RemoveDiacriticsFromWchar(int w) {
  switch (w) {
    case L'á': return L'a';
    case L'ä': return L'a';
    case L'č': return L'c';
    case L'ď': return L'd';
    case L'é': return L'e';
    case L'í': return L'i';
    case L'ĺ': return L'l';
    case L'ľ': return L'l';
    case L'ň': return L'n';
    case L'ó': return L'o';
    case L'ô': return L'o';
    case L'ŕ': return L'r';
    case L'ř': return L'r';
    case L'š': return L's';
    case L'ť': return L't';
    case L'ú': return L'u';
    case L'ů': return L'u';
    case L'ý': return L'y';
    case L'ž': return L'z';
    case L'Á': return L'A';
    case L'Ä': return L'A';
    case L'Č': return L'C';
    case L'Ď': return L'D';
    case L'É': return L'E';
    case L'Í': return L'I';
    case L'Ĺ': return L'L';
    case L'Ľ': return L'L';
    case L'Ň': return L'N';
    case L'Ó': return L'O';
    case L'Ô': return L'O';
    case L'Ŕ': return L'R';
    case L'Ř': return L'R';
    case L'Š': return L'S';
    case L'Ť': return L'T';
    case L'Ú': return L'U';
    case L'Ů': return L'U';
    case L'Ý': return L'Y';
    case L'Ž': return L'Z';
    case L'—': return L'-';
    case L'–': return L'-';
    case L'ű': return L'u';
    case L'ő': return L'o';
    case L'ü': return L'u';
    case L'ö': return L'o';
    case L'Ű': return L'U';
    case L'Ő': return L'O';
    case L'Ü': return L'U';
    case L'Ö': return L'O';
  }
  return w;
}

#endif // __UTF8_UTILS_H_
