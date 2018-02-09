#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

/*
 * passes formatted msg to perror and exits.
 */
void fatal(const char *format, ...)
{
        va_list ap;
        va_start(ap, format);
        char msg[FLAG_ERR_MSG_SIZE];
        vsnprintf(msg, 512, format, ap);
        va_end(ap);
        perror(msg);
        exit(1);
}
