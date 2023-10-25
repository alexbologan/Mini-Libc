// SPDX-License-Identifier: BSD-3-Clause

#include <string.h>

char *strcpy(char *destination, const char *source)
{
	char *dest = destination; // Create a copy of the destination pointer for returning

    while (*source != '\0') {
        *dest = *source;
        dest++;
        source++;
    }
    *dest = '\0'; // Null-terminate the destination string

    return destination;
}

char *strncpy(char *destination, const char *source, size_t len)
{
	char *dest = destination;

    while (len-- && *source != '\0') {
        *dest = *source;
        dest++;
        source++;
    }
	if (len + 1 != 0) {
		while (len--) {
			*dest = '\0';
			dest++;
		}
	}

	return destination;
}

char *strcat(char *destination, const char *source)
{
	char *dest = destination;
	while (*dest != '\0') {
		dest++;
	}

	while (*source != '\0') {
		*dest = *source;
		dest++;
		source++;
	}

	*dest = '\0';
	return destination;
}

char *strncat(char *destination, const char *source, size_t len)
{
	char *dest = destination;
	while (*dest != '\0') {
		dest++;
	}

	while (*source != '\0' && len--) {
		*dest = *source;
		dest++;
		source++;
	}

	*dest = '\0';
	return destination;
}

int max(int a, int b) {
	if (a > b)
		return a;
	return b;
}

int strcmp(const char *str1, const char *str2)
{
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
	size_t i = 0;

	for (; *str != '\0'; str++, i++)
		;

	return i;
}

char *strchr(const char *str, int c)
{
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
	while (*haystack != '\0') {
		if (*haystack == *needle) {
			const char *copyhaystack = haystack;
			copyhaystack++;
			const char *copyneedle = needle;
			copyneedle++;
			while (*copyneedle != '\0') {
				if (*copyhaystack != *copyneedle) {
					break;
				}
				copyhaystack++;
				copyneedle++;
			}
			if (*copyneedle == '\0') {
				return (char *)haystack;
			}
		}
		haystack++;
	}
	return NULL;
}

char *strrstr(const char *haystack, const char *needle)
{
	int len1 = strlen(haystack) - 1;
	int len2 = strlen(needle) - 1;
	haystack += strlen(haystack) - 1;
	needle += strlen(needle) - 1;

	while (len1--) {
		if (*haystack == *needle) {
			int copylen2 = len2;
			const char *copyhaystack = haystack;
			copyhaystack--;
			const char *copyneedle = needle;
			copyneedle--;

			while (copylen2--) {
				if (*copyhaystack != *copyneedle) {
					break;
				}
				copyhaystack--;
				copyneedle--;
			}

			if (copylen2 == -1) {
				return (char *)++copyhaystack;
			}
		}
		haystack--;
	}

	return NULL;
}

void *memcpy(void *destination, const void *source, size_t num)
{
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
	int count = 0, copylen = num;
	char const *copystr1 = (const char *)ptr1;
	char const *copystr2 = (const char *)ptr2;
	while (*copystr1 != '\0' && *copystr2 != '\0' && num--) {
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

	if (strlen((const char *)ptr1) > strlen((const char *)ptr2)) {
		return 1;
	}
	return -1;
}

void *memset(void *source, int value, size_t num)
{
	char *src = (char *)source;
	while (num--) {
		*src = value;
		src++;
	}

	return source;
}
