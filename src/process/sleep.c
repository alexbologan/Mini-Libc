#include <unistd.h>
#include <errno.h>
#include <internal/syscall.h>
#include <time.h>

unsigned int sleep(unsigned int seconds){
    struct timespec req, rem;
    req.tv_sec = (long)seconds;
    req.tv_nsec = 0;

    while (nanosleep(&req, &rem) == -1) {
        if (errno == EINTR) {
            // Sleep was interrupted; update the remaining time and continue.
            req = rem;
        } else {
            // An error occurred; return the remaining time.
            return (unsigned int)rem.tv_sec;
        }
    }
    return 0;
}
