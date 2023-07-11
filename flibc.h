/* MIT License
#
# Copyright (c) 2020 Ferhat Geçdoğan All Rights Reserved.
# Distributed under the terms of the MIT License.
#
# */

/* 
	Fegeya Single Header - C11 Library.
	
	Will be implemented:
		<locale.h> -> setlocale
		<stdio.h>  -> getchar, puts, fget, getc etc.
		<math.h>   -> pow, fabs
		<string.h> -> almost all functions.
		etc...


	Why?
	I don't know, really.
*/



#ifndef F_LIB_C_H_
#define F_LIB_C_H_

/* <stddef.h> implementation */
/* size_t */

typedef __SIZE_TYPE__ size_t;

/* ptrdiff_t */
typedef __PTRDIFF_TYPE__ ptrdiff_t;

#ifndef NULL /* make sure NULL isn't already defined */
#define NULL ((void*)0)
#endif

/* <string.h> implementation */

/* 
changed functions to be inline
for better performance

this is because inline substitute's the code in the code directly
rather than running the function as a functions

this helps the compiler with optimization
*/

/* memchr */
inline void* memchr(const void* s, int c, size_t len); 

/* strcat */
inline char* strcat(char* str_1, const char* str_2);

/* strlen */
inline size_t strlen(const char* str);

/* <stdio.h> implementation */
#ifndef EOF /* make sure EOF isn't already defined */
#define EOF (-1)
#endif

/* use the same base _IO_FILE as the standard library does */
struct _IO_FILE;
typedef struct _IO_FILE FILE;

/* make sure stdin, stdout and stderr aren't redefined */
#ifndef stdin
#define stdin (stdin)
extern FILE* const stdin;

#define stdout (stdout)
extern FILE* const stdout;

#define stderr (stderr)
extern FILE* const stderr;
#endif

/* <stdarg.h> implementation */
typedef __builtin_va_list va_list;

#define va_start(ap, param) __builtin_va_start((ap), (param))
#define va_arg(ap, type)    __builtin_va_arg((ap), (type))
#define va_end(ap)          __builtin_va_end((ap))
#define va_copy(dest, src)  __builtin_va_copy((dest), (src))

/* <ctype.h> implementation */

/* 
change char to int
this is it matches the standard library's define
*/
inline int isalpha(int ch);
inline int isalnum(int ch);
inline int isblank(int ch);
inline int isupper(int ch);
inline int islower(int ch);
inline int isdigit(int ch);
inline int isprint(int ch);

inline int toupper(int ch);
inline int tolower(int ch);

/* 
most single-header files use this to seperate source code from define code

although this library is kinda small, it's still nice to have
*/
#ifdef F_LIB_C_IMPLEMENTATION

void* memchr(const void* s, int c, size_t len) {
	/* removed N, you can just use _nstr for everything! :) */
	const char *_str = (const char*)s;
	
	while(((void*)_str - s) < len) {
		_str++;
		
		if(*_str == c)
			return (void*)_str;
	}
	
	return (NULL);
}

/* just simplified this code a little */
char* strcat(char* str_1, const char* str_2) {
	char *copy_str_1 = str_1;

	str_1 += strlen(str_1);
      
    while (*str_1++ = *str_2++);
      
    return copy_str_1;
}

size_t strlen(const char* str) {
	/* removed index check, you can just iterate using the char* */
	char* s;
	for (s = (char*)str; *s; s++);

	return (s - str);
}


/* powered-by is[lower-upper]! */
int isalpha(int ch) {
	return (isupper(ch) || islower(ch));
}

/* powered-by is[alpha-digit]! */
int isalnum(int ch) {
  	return (isalpha(ch) || isdigit(ch));
}

int isblank(int ch) {
	return (ch == ' ' || ch == '\t');
}

int isupper(int ch) {
	return (ch >= 'A' && ch <= 'Z');
}

int islower(int ch) {
	return (ch >= 'a' && ch <= 'z');
}

int isdigit(int ch) {
	return (ch >= '0' && ch <= '9');
}

int isprint(int ch) {
  	return (ch >= 0x20 && ch <= 0x7E);
}

int toupper(int ch) {
	if(islower(ch) == 1) ch = ch - 32; /* a - 32 = A */
	
	return ch;
}

int tolower(int ch) {
	if(isupper(ch) == 1) ch = ch + 32; /* A + 32 = a */
	
	return ch;
}

#endif /* F_LIB_C_IMPLEMENTATION */
#endif // F_LIB_C_H
