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
const int BUFFER_SIZE = 32 * 1024 * 1024;    /* 32 Mb */
char* buffer;


int read_envnum(const char* name) {
    char* value_str = getenv(name);
    if (value_str == NULL) {
        fprintf(stderr, ERROR " read_envnum: not found %s environment variable\n", name);
        exit(1);
    }
    return atoi(value_str);
}

const char* pretty_memory(int bytes) {
    char* s = calloc(128, sizeof(char));
    if (bytes < 1024) {
        sprintf(s, "%d B", bytes);
    } else if (bytes < 1024 * 1024) {
        sprintf(s, "%g KB", (double)bytes / 1024);
    } else {
        sprintf(s, "%g MB", (double)bytes / 1024 / 1024);
    }
    return s;
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

double benchmark_accesstime(int num_fragments, int fragmentsize) {
    long long start_time, end_time;
    long long elapsed_time;
    double access_time;

    int fragments_end = num_fragments * fragmentsize;
    assert(fragments_end <= BUFFER_SIZE);

    start_time = time_ns();
    for (int offset = 0; offset < fragmentsize; ++offset) {
        for (int i = offset; i < fragments_end; i += fragmentsize) {
            buffer[i] = i;
        }
    }
    end_time = time_ns();

    elapsed_time = end_time - start_time;
    return (double)elapsed_time / fragments_end;
}

int main() {
    /* Read options */
    int FRAGMENT_SIZE = read_envnum("FRAGMENT");
    int NUM_WALKS = read_envnum("WALKS");
    fprintf(stdout, INFO " Fragment size: %s\n", pretty_memory(FRAGMENT_SIZE));
    fprintf(stdout, INFO " # of walks: %d\n", NUM_WALKS);

    /* Allocate the buffer with zeroes */
    buffer = calloc(BUFFER_SIZE, sizeof(char));
    fprintf(stdout, INFO " Buffer has been allocated with %s\n", pretty_memory(BUFFER_SIZE));

    /* Results */
    double sum_accesstime[MAX_NUMFRAGMENTS];
    for (int i = 0; i < MAX_NUMFRAGMENTS; ++i)
        sum_accesstime[i] = 0.0;

    /* Benchmark */
    for (int walk = 0; walk < NUM_WALKS; ++walk) {
        for (int num_fragments = 1; num_fragments <= MAX_NUMFRAGMENTS; ++num_fragments) {
            double accesstime = benchmark_accesstime(num_fragments, FRAGMENT_SIZE);
            sum_accesstime[num_fragments - 1] += accesstime;
        }
        fprintf(stdout, BENCHMARK " %d / %d\n", walk, NUM_WALKS);
        fflush(stdout);
    }

    /* Print */
    for (int num_fragments = 1; num_fragments <= MAX_NUMFRAGMENTS; ++num_fragments) {
        double access_time = sum_accesstime[num_fragments - 1] / NUM_WALKS;
        fprintf(stdout, BENCHMARK " # fragments = %d\taccess (ns) = %0.1lf\n",
            num_fragments, access_time);
    }

    return 0;
}
