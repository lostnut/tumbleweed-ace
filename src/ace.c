#include "ace.h"

struct Ace new_ace(FILE *f)
{
        struct Ace ace;
        if(fscanf(f, "%s", ace.hz) != 1)
                printf("scanf error\n");
        return ace;
}
