#include "die.h"

void Die(char *function, char *message)
{
        printf("Error in function %s:\n", function);
        printf("%s\n", message);
        exit(EXIT_FAILURE);
}
