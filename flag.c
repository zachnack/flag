
#include <stdbool.h>

#include "flag.h"

/*
 * Flagset contains a number of flags, and
 * the remaining arguments in argc and argv.
 */
static struct {
        int argc;
        const char *argv[FLAG_MAX_ARGS];
        const char *usage;
        int nflags;
        Flag flags[FLAG_MAX];
        int nsize; /* size of largest flag in bytes */
} flagset;

/*
 * Check if an argument is a flag.
 */
static inline bool is_flag(const char *arg)
{
        return strlen(s) > 2 && s[0] == '-';
}

/*
 * Find the flag matching arg.
 */
static Flag *flag_find(const char *arg)
{
        for (int i = 0; i < flagset.nflags; i++) {
                Flag *flag = &flagset.flags[i];
                if (strcmp(arg + 2, flag->name) == 0) {
                        flagset.nsize = strlen(arg);
                        return flag;
                }
        }
        return NULL;
}
