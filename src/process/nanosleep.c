#include <time.h>
#include <errno.h>
#include <internal/syscall.h>

int nanosleep(const struct timespec *rqtp, struct timespec *rmtp) {
	// Call the system call for nanosleep
    int ret = syscall(__NR_nanosleep, rqtp, rmtp);

	// Check if the return value is negative, indicating an error
	if (ret < 0) {
		errno = -ret; // Set errno to an error given by the syscall
		return -1; // Return -1 to signal failure
	}

	return ret;
}
