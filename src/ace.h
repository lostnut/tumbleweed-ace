#include <stdio.h>
#include "die.h"

struct Ace {
        char hz[11];
        double aw;
        double tz;
        char hd[11];
};

struct Ace NewAce(FILE *f);
