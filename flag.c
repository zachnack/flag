
#include <stdbool.h>

#include "flag.h"

/*
 * flagset contains a number of flags, and
 * the remaining arguments in argc and argv.
 */
static struct {
        int argc;
        const char *argv[FLAG_MAX_ARGS];
        const char *usage;
        int nflags;
        Flag flags[FLAG_MAX];
	int nsize;	/* size of largest flag in bytes */
} flagset;

