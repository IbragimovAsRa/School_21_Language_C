#ifndef SRC_S21_STRING_H_
#define SRC_S21_STRING_H_

#define s21_NULL ((void *)0)

#include <stdbool.h>
#include <stdarg.h>
#include <stdlib.h>

typedef long unsigned s21_size_t;

void *s21_memchr(const void *str, int c, s21_size_t n);

int s21_memcmp(const void *str1, const void *str2, s21_size_t n);

void *s21_memcpy(void *dest, const void *src,
                 s21_size_t n); // If the arrays overlap, the result of copying will be undefined.

void *s21_memmove(void *dest, const void *src, s21_size_t n); // Arrays (memory areas) may overlap.

char *s21_strcat(char *dest, const char *src);

char *s21_strchr(const char *str, int c);

int s21_sscanf(const char *str, const char *format, ...);


char *s21_strpbrk(const char *str1, const char *str2);

s21_size_t s21_strspn(const char *str1, const char *str2);


// ------------------------------------------------------------------------
// additional functions

s21_size_t s21_strlen(const char *str);

// ------------------------------------------------------------------------


#endif  // SRC_S21_STRING_H_
