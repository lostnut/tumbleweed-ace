#include "ace.h"

struct Ace NewAce(FILE *f)
{
        struct Ace ace;
        char dummy[MAX_STR];
        /* Read first line */
        if (fgets(dummy, sizeof dummy, f) == NULL)
                Die("NewAce", "Could not read first line");
        if (sscanf(dummy, "%11s %lf %lf %11s",
                                ace.hz, &ace.aw, &ace.tz, ace.hd) != 4)
                Die("NewAce", "Could not parse first line");
        /* Read second line */
        if(fgets(ace.hk, 71, f) == NULL)
                Die("NewAce", "Could not parse HK field");
        if(fgets(ace.hm, 11, f) == NULL)
                Die("NewAce", "Could not parse HM field");
        /* Read IZ/AW array */
        for(int i = 0; i < 16; i++){
                if(fscanf(f, "%d", &ace.iz[i]) != 1){
                        Die("NewAce", "Could not parse IZ[%d]", i);
                }               
                if(fscanf(f, "%lf", &ace.awr[i]) != 1){
                        Die("NewAce", "Could not parse AW[%d]", i);
                }
        }
        return ace;
}
