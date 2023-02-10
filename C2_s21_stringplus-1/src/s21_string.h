

#define s21_NULL ((void *)0)

typedef long unsigned s21_size_t;

void *s21_memchr(const void *str, int c, s21_size_t n);
int s21_memcmp(const void *str1, const void *str2, s21_size_t n);
s21_size_t s21_strlen(const char *str)
