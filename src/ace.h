#include <stdio.h>
#include "die.h"

#define MAX_STR 256

struct Ace {
        char hz[11];
        double aw;
        double tz;
        char hd[11];
        char hk[71];
        char hm[11];
};

struct Ace NewAce(FILE *f);
