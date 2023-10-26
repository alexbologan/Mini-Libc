// SPDX-License-Identifier: BSD-3-Clause

#include <sys/mman.h>
#include <errno.h>
#include <internal/syscall.h>

void *mmap(void *addr, size_t length, int prot, int flags, int fd, off_t offset)
{
    // Check for bad files
	if (fd != -1) {
        errno = 9;  // Set errno to indicate a bad file descriptor
        return MAP_FAILED;
    }

    // Call the syscall to map memory with the specified parameters
	void *ret = (void *)syscall(__NR_mmap, addr, length, prot, flags, fd, offset);

	if (ret == (void *)-22) {
        errno = 22;  // Set errno to indicate an invalid argument
        return MAP_FAILED;
    }

	if (ret == MAP_FAILED) {
        errno = -errno;  // Set errno on failure
    }

    return ret;
}

void *mremap(void *old_address, size_t old_size, size_t new_size, int flags)
{
    // Declare a void pointer 'ret' to store the return value of the syscall
	void *ret = (void *)syscall(__NR_mremap, old_address, old_size, new_size, flags);

	if (ret == MAP_FAILED) {
        errno = -errno;  // Set errno on failure
    }

    return ret;
}

int munmap(void *addr, size_t length)
{
    // Call the syscall to unmap the specified memory region
	int ret = syscall(__NR_munmap, addr, length);

    // Check if 'ret' is less than 0, which indicates an error
	if (ret < 0) {
		errno = -ret; // Set errno to an error given by the syscall
		return -1; // Return -1 to signal failure
	}

	return ret;
}
