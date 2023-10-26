// SPDX-License-Identifier: BSD-3-Clause

#include <unistd.h>
#include <internal/syscall.h>
#include <errno.h>
#include <sys/types.h>

int ftruncate(int fd, off_t length)
{
	// Call the system call for ftruncate
	int ret = syscall(__NR_ftruncate, fd, length);

	// Check if the return value is negative, indicating an error
	if (ret < 0) {
		errno = -ret; // Set errno to an error given by the syscall
		return -1; // Return -1 to signal failure
	}

	return ret;
}
