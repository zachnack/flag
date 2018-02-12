#include <errno.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "flag.h"

static struct {
        const char *usage_line;
        int nflags;
        struct flag flags[FLAG_MAX];
        int argc;
        const char *argv[FLAG_MAX_ARGS];
} set;

/* passes formatted msg to perror and exits. Adds a newline. */
void fatal(const char *format, ...)
{
        va_list ap;
        va_start(ap, format);
        char msg[FLAG_ERR_MSG_SIZE];
        vsnprintf(msg, FLAG_ERR_MSG_SIZE, format, ap);
        va_end(ap);
        fputs(msg, stderr);
        /* if errno print textual representation of errno value. */
        if (errno)
                fprintf(stderr, ": %s", strerror(errno));
        fputs("\n", stderr);
        exit(1);
}

void flag_bool(bool *p,const char *name, const char *help)
{
        if (set.nflags >= FLAG_MAX)
                fatal("too many flags declared.\n");
        struct flag f = {.name = name, .help = help, .value.b = p };
        set.flags[set.nflags++] = f;
};

void flag_int(int *p, const char *name, const char *help)
{
	if (set.nflags >= FLAG_MAX)
		fatal("too many flags declared.\n");
	struct flag f = {.name = name, .help = help, .value.i = p };
	set.flags[set.nflags++] = f;
};

void flag_str(const char **p, const char *name, const char *help)
{
	if (set.nflags >= FLAG_MAX)
		fatal("too many flags declared.\n");
	struct flag f = {.name = name, .help = help, .value.s = p };
	set.flags[set.nflags++] = f;
};

