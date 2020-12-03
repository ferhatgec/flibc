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
typedef unsigned long size_t;

/* ptrdiff_t */
typedef signed long ptrdiff_t;

#define NULL ((void*)0)

/* <string.h> implementation */

/* memchr */
void* memchr(const void* s, int c, size_t len); 

/* strcat */
char* strcat(char* str_1, const char* str_2);

/* strlen */
size_t strlen(const char* str);

/* <ctype.h> implementation */
int isalpha(char ch);
int isalnum(char ch);
int isblank(char ch);
int isupper(char ch);
int islower(char ch);
int isdigit(char ch);
int isprint(char ch);

int toupper(char ch);
int tolower(char ch);

void* memchr(const void* s, int c, size_t len) {
	const char *_str = (const char*)s;
	
	size_t n = 0;
	
	while(n < len) {
		n++;
		
		if(_str[n] == c)
			return (void*)&_str[n];
	}
	
	return (NULL);
}

char* strcat(char* str_1, const char* str_2) {
	char *copy_str_1 = str_1;

    while(*str_1)
      str_1++;
      
    while (*str_1++ = *str_2++)
      ;
      
    return copy_str_1;
}

size_t strlen(const char* const str) {
    size_t i;
    
    for(i = 0; str[i] != '\0'; i++)
    	;
    
    return i;
}


/* powered-by is[lower-upper]! */
int isalpha(char ch) {
	return (isupper(ch) || islower(ch));
}

/* powered-by is[alpha-digit]! */
int isalnum(char ch) {
  	return (isalpha(c) || isdigit(c));
}

int isblank(char ch) {
	return (c == ' ' || c == '\t');
}

int isupper(char ch) {
	return (ch >= 'A' && ch <= 'Z');
}

int islower(char ch) {
	return (ch >= 'a' && ch <= 'z');
}

int isdigit(char ch) {
	return (ch >= '0' && ch <= '9');
}

int isprint(char ch) {
  	return (ch >= 0x20 && ch <= 0x7E);
}

int toupper(char ch) {
	if(islower(ch) == 1) ch = ch - 32; /* a - 32 = A */
	
	return ch;
}

int tolower(char ch) {
	if(isupper(ch) == 1) ch = ch + 32; /* A + 32 = a */
	
	return ch;
}

#endif // F_LIB_C_H
