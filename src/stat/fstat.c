// SPDX-License-Identifier: BSD-3-Clause

#include <sys/stat.h>
#include <internal/syscall.h>
#include <errno.h>

int fstat(int fd, struct stat *st)
{
	// Call the system call for fstat
	int ret = syscall(__NR_fstat, fd, st);

	// Check if the return value is negative, indicating an error
	if (ret < 0) {
		errno = -ret; // Set errno to an error given by the syscall
		return -1; // Return -1 to signal failure
	}

	return ret;
}
