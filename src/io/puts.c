#include <unistd.h>
#include <string.h>

int puts(const char *str) {
    size_t length = strlen(str);

    write(1, str, length);

    // Write a newline character to move to the next line.
    char newline = '\n';
    write(1, &newline, 1);

    return 0;
}
