#pragma once
#include <stdio.h>
#include "malloc.h"
#include <stdbool.h>

// возвращает длину строки **
size_t length(const char * string);

// копирует n байт из области памяти src в dest **
void * memory_copy(void * dest, const void * source, size_t n);

// возвращает указатель на первое вхождение значения c среди первых n байтов s или NULL, если не найдено **
void * memory_char(const char *s, char c, size_t n);

// сравнивает первые n символов в областях памяти **
int memory_compare(const char * s1, const char * s2, size_t n);

// дописывает строку src в конец dest **
char * string_concat(char * dest, const char * src);
char * string_concat_n(char * dest, const char * src, size_t n);

// копирует строку из одного места в другое **
char * string_copy(char * to, const char * from);
// копирует до n байт строки из одного места в другое **
char * string_copy_n(char * to, const char * from, size_t n);

// создаёт идентичную строку и возвращает указатель на неё **
char * string_dup(const char * str);

// находит первое вхождение любого символа, перечисленного в accept **
char * string_break(const char * s, const char * accept);
