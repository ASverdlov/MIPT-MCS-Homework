#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/errno.h>
#include <time.h>

#define GREEN "\x1b[1;32m"
#define RED "\x1b[1;31m"
#define RESET "\x1b[0m"
#define ERROR RED "[ERROR]" RESET
#define BENCHMARK GREEN "[BENCHMARK]" RESET
#define INFO GREEN "[BENCHMARK]" RESET

const int MAX_NUMFRAGMENTS = 32;             /* will bench from 1 to MAX_NUMFRAGMENTS */
const int BUFFER_SIZE = 1024 * 1024 * 1024;  /* 1GB */
char* buffer;


int read_envnum(const char* name) {
    char* value_str = getenv(name);
    if (value_str == NULL) {
        fprintf(stderr, ERROR " read_envnum: not found %s environment variable\n", name);
        exit(1);
    }
    return atoi(value_str);
}

/* Returns current time in nanoseconds.
 * On Mac OSX version >= 10.12 must be used for CLOCK_MONOTONIC to work
 */
long long time_ns() {
    struct timespec t;
    int err;

    err = clock_gettime(CLOCK_MONOTONIC, &t);
    if (err == -EINVAL) {
        fprintf(stderr, ERROR " clock_gettime: CLOCK_MONOTONIC is not available. If you are on OSX, check that OSX version >= 10.12\n");
        exit(1);
    }

    return t.tv_nsec + t.tv_sec * 1000LL * 1000 * 1000;
}

void warmup_cache() {
    for (int i = BUFFER_SIZE - 1; i >= 0; --i) {
        (char)buffer[i];
    }
    fprintf(stdout, INFO " Cache has been warmed up.\n");
}

void benchmark(int num_fragments, int fragmentsize) {
    long long start_time, end_time;
    long long elapsed_time;
    double access_time;

    int fragments_end = num_fragments * fragmentsize;
    assert(fragments_end <= BUFFER_SIZE);

    start_time = time_ns();
    for (int offset = 0; offset < fragmentsize; ++offset) {
        for (int i = offset; i < fragments_end; i += fragmentsize) {
            (char)buffer[i + offset];
        }
    }
    end_time = time_ns();

    elapsed_time = end_time - start_time;
    access_time = (double)elapsed_time / fragments_end;
    fprintf(stdout, BENCHMARK " # fragments = %d\taccess (ns) = %lf\telapsed (ns) = %lld\n",
        num_fragments, access_time, elapsed_time);
}

int main() {
    /* Read options */
    int FRAGMENT_SIZE = read_envnum("FRAGMENT");
    fprintf(stdout, INFO " Fragment size: %d bytes\n", FRAGMENT_SIZE);

    /* Allocate the buffer with zeroes */
    buffer = calloc(BUFFER_SIZE, sizeof(char));
    fprintf(stdout, INFO " Buffer has been allocated with %d bytes\n", BUFFER_SIZE);

    warmup_cache();
    for (int num_fragments = 1; num_fragments <= MAX_NUMFRAGMENTS; ++num_fragments) {
        benchmark(num_fragments, FRAGMENT_SIZE);
    }

    return 0;
}
