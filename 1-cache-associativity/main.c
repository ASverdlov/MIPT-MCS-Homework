#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/errno.h>
#include <time.h>

int read_envnum(const char* name) {
    char* value_str = getenv(name);
    assert(value_str != NULL);
    return atoi(value_str);
}

/* Returns current time in nanoseconds.
   On Mac OSX version >= 10.12 must be used for CLOCK_MONOTONIC to work */
int time_ns() {
    struct timespec t;
    int err;

    err = clock_gettime(CLOCK_MONOTONIC, &t);
    if (err == -EINVAL) {
        fprintf(stderr, "[ERROR] If you are on OSX, check that OSX version >= 10.12\n");
        exit(1);
    }

    return t.tv_nsec + t.tv_sec * 1000 * 1000 * 1000;
}

int main() {
    int BUFFER_SIZE;
    int STEP;
    char* buffer;

    /* Read options */
    BUFFER_SIZE = read_envnum("CASSOC_BUFFER_SIZE");
    STEP = read_envnum("CASSOC_STEP");
    assert(BUFFER_SIZE % STEP == 0);

    /* Allocate the buffer with zeroes */
    buffer = calloc(BUFFER_SIZE, sizeof(char));

    /* Benchmark L1 access time */
    int start_time = time_ns();
    int dummy;
    for (int i = 0; i < BUFFER_SIZE; ++i) {
        dummy = buffer[i];
    }
    int elapsed_time = time_ns() - start_time;
    int access_time = elapsed_time / BUFFER_SIZE;
    fprintf(stdout, "[BENCHMARK] total time = %d, average access time = %d\n",
        elapsed_time, access_time);

    return 0;
}
