#include <unistd.h>
#include <string.h>

int puts(const char *str) {
    // Calculate the length of the input string using strlen
    size_t length = strlen(str);

    // Write the content of 'str' to the standard output
    write(1, str, length);

    // Write a newline character to move to the next line.
    char newline = '\n';

    // Write a newline character to move to the next line
    write(1, &newline, 1);

    // Return 0 to indicate successful execution
    return 0;
}
