#include "string.h"

size_t length(const char * string) {
    size_t length = 0;
    while (1) {
        if (string[length] == '\0') break;
        length++;
    }
    return (size_t) length;
}

void * memory_copy(void * dest, const void * source, size_t n) {
    size_t srcLength = length(source);
    for (int i = 0; i < n && i < srcLength; i++ ) ((char *) dest)[i] = ((char *) source)[i];
    return dest;
}

// **
void * memory_char(const char * s, char c, size_t n) {
    void * ptr = s;
    size_t stringLength = length(s);
    for (int i = 0; i < n && i < stringLength; i++) {
        if (*(s + i) == c) {
            ptr = s + i;
            break;
        }
    }
    return ptr;
}

int memory_compare(const char * s1, const char * s2, size_t n) {
    size_t s1len = length(s1);
    size_t s2len = length(s2);
    size_t min = (s1len >= s2len)? s2len : s1len;
    int res = 0;
    for (int i = 0; i < n && i < min; i++) {
        bool exp = (s1[i] == s2[i]);
        res += (exp)? 1 : 0;
        if (!exp) break;
    }
    return res;
}

// Конкатенацию сделал коряво,
// потому что realloc (чтоб увеличть dest без каких либо извращений) отказался работать,
// выдавал сегфолт и поэтому пришлось извратиться и сделать через доп. массив
char * string_concat(char * dest, const char * src) {
    size_t destinationLen = length(dest);
    size_t sourceLen = length(src);
    char tmp[destinationLen];
    for (int i = 0; i < destinationLen; i++) tmp[i] = dest[i];
    dest = (char *) malloc(destinationLen + sourceLen);
    for (int i = 0; i < destinationLen; i++) dest[i] = tmp[i];
    for (int i = 0; i < sourceLen; i++) dest[i + destinationLen] = src[i];
    return dest;
}
char * string_concat_n(char * dest, const char * src, size_t n) {
    size_t destLen = length(dest);
    size_t srcLen = length(src);
    char tmp[destLen];
    for (int i = 0; i < destLen; i++) tmp[i] = dest[i];
    dest = (char *) malloc(destLen + (srcLen > n)? n : srcLen);
    for (int i = 0; i < destLen; i++) dest[i] = tmp[i];
    for (int i = 0; i < srcLen && i < n; i++) dest[i + destLen] = src[i];
    return dest;
}

char * string_copy(char * to, const char * from) {
    size_t srcLen = length(from);
    to = (char *) malloc(srcLen);
    for (int i = 0; i < srcLen; i++) *(to + i) = *(from + i);
    return to;
}
char * string_copy_n(char * to, const char * from, size_t n) {
    size_t srcLen = length(from);
    to = (char *) malloc((srcLen > n)? n : srcLen);
    for (int i = 0; i < srcLen && i < n; i++) *(to + i) = *(from + i);
    return to;
}

char * string_dup(const char * str) {
    size_t len = length(str);
    char * new = (char *) malloc(len);
    for (int i = 0; i < len; i++) new[i] = str[i];
    return new;
}

char * string_break(const char * s, const char * accept) {
    size_t stringLen = length(s);
    size_t acceptedLen = length(accept);
    for (int i = 0; i < stringLen; i++) {
        for (int j = 0; j < acceptedLen; j++) {
            if (s[i] == accept[j]) return &s[i];
        }
    }
    return NULL;
}
