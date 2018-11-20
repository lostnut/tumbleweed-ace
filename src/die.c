#include "die.h"

void Die(const char *function, const char *format, ...)
{
        printf("Error in function %s:\n", function);
        va_list argp;
        va_start(argp, format);
        vfprintf(stderr, format, argp);
        va_end(argp);
        exit(EXIT_FAILURE);
}
