#include "ace.h"

struct Ace NewAce(FILE *f)
{
        struct Ace ace;
        if(fscanf(f, "%s", ace.hz) != 1)
                Die("NewAce", "Could not parse HZ field");
        if(fscanf(f, "%lf", ace.aw) != 1)
                Die("NewAce", "Could not parse AW field");
        if(fscanf(f, "%lf", ace.tz) != 1)
                Die("NewAce", "Could not parse TZ field");
        if(fscanf(f, "%s", ace.hd) != 1)
                Die("NewAce", "Could not parse HD field");
        return ace;
}
