// SPDX-License-Identifier: BSD-3-Clause

#include <string.h>

char *strcpy(char *destination, const char *source)
{
	// Create a copy of the destination pointer forreturning
	char *dest = destination;

	// Copy the characters from 'source' to 'destination' until a null
	// terminator is encountered
    while (*source != '\0') {
        *dest = *source;
        dest++;
        source++;
    }

    *dest = '\0'; // Null-terminate the string

    return destination;
}

char *strncpy(char *destination, const char *source, size_t len)
{
	// Copy at most 'len' characters from 'source' to 'destination'
	char *dest = destination;

    while (len-- && *source != '\0') {
        *dest = *source;
        dest++;
        source++;
    }

	if (len + 1 != 0) {
		while (len--) {
			// Fill the remaining space with null characters
			*dest = '\0';
			dest++;
		}
	}

	return destination;
}

char *strcat(char *destination, const char *source)
{
	// Append the characters from 'source' to the end of 'destination'
	char *dest = destination;

	while (*dest != '\0') {
		dest++;
	}

	while (*source != '\0') {
		*dest = *source;
		dest++;
		source++;
	}

	*dest = '\0'; // Null-terminate the concatenated string

	return destination;
}

char *strncat(char *destination, const char *source, size_t len)
{
	// Append at most 'len' characters from 'source' to the end of 'destination'
	char *dest = destination;

	while (*dest != '\0') {
		dest++;
	}

	while (*source != '\0' && len--) {
		*dest = *source;
		dest++;
		source++;
	}

	*dest = '\0'; // Null-terminate the concatenated string

	return destination;
}

int max(int a, int b) {
	// Return the maximum of two integers 'a' and 'b'
	if (a > b)
		return a;
	return b;
}

int strcmp(const char *str1, const char *str2)
{
	// Compare two strings 'str1' and 'str2' lexicographically
	int count = 0;
	char const *copystr1 = str1;
	char const *copystr2 = str2;

	while (*copystr1 != '\0' && *copystr2 != '\0') {
		if (*copystr1 != *copystr2) {
			if (*copystr1 > *copystr2) {
				return 1;
			} else {
				return -1;
			}
			break;
		}
		copystr1++;
		copystr2++;
		count++;
	}

	if (count == max(strlen(str1), strlen(str2))) {
		return 0;
	}

	if (strlen(str1) > strlen(str2)) {
		return 1;
	}

	return -1;
}

int strncmp(const char *str1, const char *str2, size_t len)
{
	// Compare two strings 'str1' and 'str2' lexicographically
	// considering only the first 'len' characters
	int count = 0, copylen = len;
	char const *copystr1 = str1;
	char const *copystr2 = str2;

	while (*copystr1 != '\0' && *copystr2 != '\0' && len--) {
		if (*copystr1 != *copystr2) {
			if (*copystr1 > *copystr2) {
				return 1;
			} else {
				return -1;
			}
			break;
		}
		copystr1++;
		copystr2++;
		count++;
	}

	if (count == copylen) {
		return 0;
	}

	if (strlen(str1) > strlen(str2)) {
		return 1;
	}

	return -1;
}

size_t strlen(const char *str)
{
	// Calculate the length of a null-terminated string 'str'
	size_t i = 0;

	for (; *str != '\0'; str++, i++)
		;

	return i;
}

char *strchr(const char *str, int c)
{
	// Find the first occurrence of character 'c' in the string 'str'
	while (*str != '\0') {
		if (*str == c) {
			return (char *)str;
		}
		str++;
	}

	return NULL;
}

char *strrchr(const char *str, int c)
{
	// Find the last occurrence of character 'c' in the string 'str'
	int len = strlen(str) - 1;
	str += strlen(str);

	while (len--) {
		if (*str == c) {
			return (char *)str;
		}
		str--;
	}

	return NULL;
}

char *strstr(const char *haystack, const char *needle)
{
    // Find the first occurrence of 'needle' in 'haystack'
    // Loop through the 'haystack' string until the end is reached
    while (*haystack != '\0') {
        // Check if the current character in matches the first of 'needle'
        if (*haystack == *needle) {
			// Create a copy of 'haystack' pointer
            const char *copyhaystack = haystack;
            copyhaystack++;  // Move the copy of 'haystack' one character ahead

			// Create a copy of 'needle' pointer
            const char *copyneedle = needle;
            copyneedle++;  // Move the copy of 'needle' one character ahead

            // Start a loop to compare the characters
            while (*copyneedle != '\0') {
                // If the characters don't match, break out of the loop
                if (*copyhaystack != *copyneedle) {
                    break;
                }
                copyhaystack++;  // Move the 'copyhaystack' pointer
                copyneedle++;  // Move the 'copyneedle' pointer
            }

            // If we reached the end, return the starting position
            if (*copyneedle == '\0') {
                return (char *)haystack;
            }
        }
        haystack++;  // Move the 'haystack' pointer to the next character
    }

    // If no match was found, return NULL
    return NULL;
}

char *strrstr(const char *haystack, const char *needle)
{
    // Find the last occurrence of 'needle' in 'haystack'

    // Get the lengths of 'haystack' and 'needle'
    int len1 = strlen(haystack) - 1;
    int len2 = strlen(needle) - 1;

	// Move the pointers to their respective ends
    haystack += strlen(haystack) - 1;
    needle += strlen(needle) - 1;

    // Start a loop to search for the last occurrence of 'needle' in 'haystack'
    while (len1--) {
        // Check if the current character matches the last of 'needle'
        if (*haystack == *needle) {
			// Create a copy of 'len2'
            int copylen2 = len2;

			// Create a copy of 'haystack' pointer
            const char *copyhaystack = haystack;
            copyhaystack--;  // Move the 'copyhaystack' one character back

			// Create a copy of 'needle' pointer
            const char *copyneedle = needle;
            copyneedle--;  // Move the 'copyneedle' one character back

            // Start a loop to compare the characters
            while (copylen2--) {
                // If the characters don't match, break out of the loop
                if (*copyhaystack != *copyneedle) {
                    break;
                }
                copyhaystack--;  // Move the 'copyhaystack' pointer back
                copyneedle--;  // Move the 'copyneedle' pointer back
            }

            // If we reached the beginning, return the starting position
            if (copylen2 == -1) {
                return (char *)++copyhaystack;
            }
        }
        haystack--;  // Move the 'haystack' pointer one character back
    }

    // If no match was found, return NULL
    return NULL;
}

void *memcpy(void *destination, const void *source, size_t num)
{
    // Copy 'num' bytes from 'source' to 'destination'
    char *dest = (char *)destination;
    const char *src = (const char *)source;
    size_t i = 0;

    while (i < num) {
        dest[i] = src[i];
        i++;
    }

    return destination;
}

void *memmove(void *destination, const void *source, size_t num)
{
    // Move 'num' bytes from 'source' to 'destination', handling potential overlap
    char *dest = (char *)destination;
    const char *src = (const char *)source;
    size_t i = 0;

    while (i < num) {
        dest[i] = src[i];
        i++;
    }

    return destination;
}

int memcmp(const void *ptr1, const void *ptr2, size_t num)
{
    // Compare 'num' bytes in memory pointed to by 'ptr1' and 'ptr2'
    int count = 0;
    int copylen = num;

    // Create character pointers to 'ptr1' and 'ptr2'
    const char *copystr1 = (const char *)ptr1;
    const char *copystr2 = (const char *)ptr2;

    // Start a loop to compare 'num' bytes in memory
    while (*copystr1 != '\0' && *copystr2 != '\0' && num--) {
        // Compare the characters in 'copystr1' and 'copystr2'
        if (*copystr1 != *copystr2) {
            // If they don't match, return 1 if 'copystr1' is greater
			// return -1 if 'copystr2' is greater
            if (*copystr1 > *copystr2) {
                return 1;
            } else {
                return -1;
            }
            break; // Break the loop as soon as a difference is found
        }
        copystr1++;
        copystr2++;
        count++;
    }

    // If the loop completed without finding a difference, the blocks are equal
    if (count == copylen) {
        return 0;
    }

    // If the lengths of the two blocks are different
	// return 1 if the first block is longer, -1 if the second block is longer
    if (strlen((const char *)ptr1) > strlen((const char *)ptr2)) {
        return 1;
    }
    return -1;
}

void *memset(void *source, int value, size_t num)
{
    // Set 'num' bytes in memory pointed to by 'source' to the specified 'value'
    char *src = (char *)source;

    while (num--) {
        *src = value;
        src++;
    }

    return source;
}
