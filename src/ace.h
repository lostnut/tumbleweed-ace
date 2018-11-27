#include <stdio.h>
#include "die.h"

#define MAX_STR 256

struct Esz {
        double *egrid;
        double *xstot;
        double *xsa;
        double *xsel;
        double *have;
};

struct Ace {
        char hz[11];
        double aw;
        double tz;
        char hd[11];
        char hk[71];
        char hm[11];
        int iz[16];
        double awr[16];
        int nxs[16];
        int jxs[32];
        struct Esz esz;
};

struct Ace new_ace(FILE *f);
