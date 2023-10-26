#ifndef __TIME_H__
#define __TIME_H__ 1

#ifdef __cplusplus
extern "C" {
#endif

// Define a structure to represent time intervals
struct timespec {
    long  tv_sec; // Seconds
    long  tv_nsec;  // Nanoseconds
};

int nanosleep(const struct timespec *req, struct timespec *rem);

#ifdef __cplusplus
}
#endif

#endif
