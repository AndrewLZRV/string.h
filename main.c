#include <stdio.h>
#include "string.h"

int main() {
    // Concatenation test
    char * str1 = "hello ";
    char * str2 = "world!;
    printf("%s", string_concat(str1, str2));
    return 0;
}
