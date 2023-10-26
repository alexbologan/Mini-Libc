// SPDX-License-Identifier: BSD-3-Clause

#include <fcntl.h>
#include <internal/syscall.h>
#include <stdarg.h>
#include <errno.h>

int open(const char *filename, int flags, ...)
{
	// Call the system call for open
    int ret = syscall(__NR_open, filename, flags);

	// Check if the return value is negative, indicating an error
	if (ret < 0) {
		errno = -ret; // Set errno to an error given by the syscall
		return -1; // Return -1 to signal failure
	}

	return ret;
}
