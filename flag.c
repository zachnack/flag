
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
        const char *version;
        int nflags;
        Flag flags[FLAG_MAX];
} flagset;

/*
 * Initialize a new flag library.
 */
void flag_init(const char *usage, const char *version)
{
        flagset.usage = usage;
        flagset.version = version;
}
