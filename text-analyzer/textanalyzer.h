#ifndef textanalyzer
#define textanalyzer
#include<string.h>
#include<stdio.h>
#include<errno.h>
extern int errno;
size_t character_count(char **);
size_t line_count(char **);
size_t word_count(char **);
int frequent_characters(char **);
int isthisspace(unsigned int);
/*isthisspace() checks  for  white-space  characters.   In  the  "C"  and "POSIX" locales, these are: space, form-feed ('\f'), newline ('\n'), carriage return
              ('\r'), horizontal tab ('\t'), and vertical tab ('\v').*/


#endif