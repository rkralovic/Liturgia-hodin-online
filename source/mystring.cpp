/***************************************************************/
/*                                                             */
/* mystring.cpp                                                */
/* (c)1999-2011 | Juraj Videky | videky@breviar.sk             */
/*                                                             */
/* description |                                               */
/* document history                                            */
/*   31/03/2000A.D. | created                                  */
/*   06/09/2001A.D. | tento popis                              */
/*   2009-08-05a.D. | pridan� funkcia substring()              */
/*   2011-04-13a.D. | sem presunut� re�azcov� funkcie equals() */
/*                                                             */
/***************************************************************/

#include "vstudio.h"

#ifndef __MYSTRING_CPP_
#define __MYSTRING_CPP_

#include <ctype.h>
#include "mystring.h"
#include "mysystem.h"

/* funkcia mystrcpy()
 * 1. zisti velkost dest -- sizeof(dest)
 * 2. kopiruje nanajvys count - 1 znakov z src do dest (pomocou strncpy)
 * 3. v kazdom pripade prida na koniec v dest '\0' (terminating null)
 */
char *mystrcpy(char *dest, char *src, short int count){
	char *ret;
	/* sizeof(dest) nefunguje pre char *dest */
	ret = strncpy(dest, src, count - 1);
	dest[count - 1] = '\0';
	return ret;
}
char *mystrcpy(char *dest, const char *src, short int count){
	char *ret;
	/* sizeof(dest) nefunguje pre char *dest */
	ret = strncpy(dest, src, count - 1);
	dest[count - 1] = '\0';
	return ret;
}

/* The strncpy function copies the initial count characters of strSource to strDest 
 * and returns strDest. If count is less than or equal to the length of strSource, 
 * a null character is not appended automatically to the copied string. 
 * If count is greater than the length of strSource, the destination string is padded 
 * with null characters up to length count. 
 * The behavior of strncpy is undefined if the source and destination strings overlap.
 * This function returns strDest. No return value is reserved to indicate an error.
 */

int substring(char *str1, char *str2){
	// vr�ti true, ak str2 je substring v re�azci str1
	return (strstr(str1, str2) != NULL);
}

/* ------------------------------------------------------------------- */
/* string comparator -- pre vsetky kombinacie dvojic
 * [const] char, [const] char
 */
short int equals(char *s1, char *s2){
	if(strcmp(s1, s2) == 0)
		return 1;
	else
		return 0;
}

short int equals(const char *s1, char *s2){
	if(strcmp(s1, s2) == 0)
		return 1;
	else
		return 0;
}

short int equals(const char *s1, const char *s2){
	if(strcmp(s1, s2) == 0)
		return 1;
	else
		return 0;
}

short int equals(char *s1, const char *s2){
	if(strcmp(s1, s2) == 0)
		return 1;
	else
		return 0;
}

/* string comparator without case sensitivity  -- pre vsetky kombinacie
 * dvojic [const] char, [const] char
 */

short int equalsi(char *is1, char *is2){
#if defined(DEFINED_strcmpi)
	if(strcmpi(is1, is2) == 0)
		return 1;
	else
		return 0;
#else
	short int i, length;
	char s1[MAX_STR], s2[MAX_STR];
	mystrcpy(s1, is1, MAX_STR);
	mystrcpy(s2, is2, MAX_STR);
	length = strlen(s1);
	for(i = 0; i < length; i++){
		s1[i] = (char)tolower(s1[i]);
	}
	length = strlen(s2);
	for(i = 0; i < length; i++){
		s2[i] = (char)tolower(s2[i]);
	}
	return equals(s1, s2);
#endif
}

short int equalsi(const char *is1, char *is2){
#if defined(DEFINED_strcmpi)
	if(strcmpi(is1, is2) == 0)
		return 1;
	else
		return 0;
#else
	short int i, length;
	char s1[MAX_STR], s2[MAX_STR];
	mystrcpy(s1, is1, MAX_STR);
	mystrcpy(s2, is2, MAX_STR);
	length = strlen(s1);
	for(i = 0; i < length; i++){
		s1[i] = (char)tolower(s1[i]);
	}
	length = strlen(s2);
	for(i = 0; i < length; i++){
		s2[i] = (char)tolower(s2[i]);
	}
	return equals(s1, s2);
#endif
}

short int equalsi(const char *is1, const char *is2){
#if defined(DEFINED_strcmpi)
	if(strcmpi(is1, is2) == 0)
		return 1;
	else
		return 0;
#else
	short int i, length;
	char s1[MAX_STR], s2[MAX_STR];
	mystrcpy(s1, is1, MAX_STR);
	mystrcpy(s2, is2, MAX_STR);
	length = strlen(s1);
	for(i = 0; i < length; i++){
		s1[i] = (char)tolower(s1[i]);
	}
	length = strlen(s2);
	for(i = 0; i < length; i++){
		s2[i] = (char)tolower(s2[i]);
	}
	return equals(s1, s2);
#endif
}

short int equalsi(char *is1, const char *is2){
#if defined(DEFINED_strcmpi)
	if(strcmpi(is1, is2) == 0)
		return 1;
	else
		return 0;
#else
	short int i, length;
	char s1[MAX_STR], s2[MAX_STR];
	mystrcpy(s1, is1, MAX_STR);
	mystrcpy(s2, is2, MAX_STR);
	length = strlen(s1);
	for(i = 0; i < length; i++){
		s1[i] = (char)tolower(s1[i]);
	}
	length = strlen(s2);
	for(i = 0; i < length; i++){
		s2[i] = (char)tolower(s2[i]);
	}
	return equals(s1, s2);
#endif
}

#endif /* __MYSTRING_CPP_ */

