#include <unistd.h>
#include <errno.h>
#include <internal/syscall.h>
#include <time.h>

unsigned int sleep(unsigned int seconds){
    // Create a timespec structure 'req' to specify the requested sleep time
    struct timespec req, rem;
    req.tv_sec = (long)seconds;
    req.tv_nsec = 0;

    // Perform nanosleep repeatedly until the requested sleep time is completed
    while (nanosleep(&req, &rem) == -1) {
        if (errno == EINTR) {
            // Sleep was interrupted, update the remaining time and continue.
            req = rem;
        } else {
            // An error occurred, return the remaining time.
            return (unsigned int)rem.tv_sec;
        }
    }
    return 0;
}
