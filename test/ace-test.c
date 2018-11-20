#include <criterion/criterion.h>
#include <stdio.h>
#include "../src/ace.h"


static FILE *f;
static struct Ace ace;
void setup(void) 
{
        if((f = fopen("test/resources/1-H-1g.jeff33.ACE", "r")) == NULL){
                printf("could not open resource file\n");
        }
        ace = NewAce(f);
}

void teardown(void) 
{
        fclose(f);
}

TestSuite(ace, .init = setup, .fini = teardown);

Test(ace, hz)
{
        cr_assert_str_eq(ace.hz, "1001.03c");
}

Test(ace, aw)
{
        cr_assert_float_eq(ace.aw, 0.999167, 1e-7);
}

Test(ace, tz)
{
        cr_assert_float_eq(ace.tz, 2.5301e-8, 1e-13);
}

Test(ace, hd)
{
        cr_assert_str_eq(ace.hd, "02/23/18");
}

Test(ace, hk)
{
        cr_assert_str_eq(ace.hk, "MAT=125 ACE file produced at NEA with NDEC                            ");
}

Test(ace, hm)
{
        cr_assert_str_eq(ace.hm, "   mat 125");
}

Test(ace, iz)
{
        int tmp[16] = {0};
        for(int i = 0; i < 16; i++)
                cr_assert_eq(ace.iz[i], tmp[i]);
}

Test(ace, awr)
{
        double tmp[16] = {0};
        for(int i = 0; i < 16; i++)
                cr_assert_eq(ace.awr[i], tmp[i]);
}

Test(ace, nxs)
{
        int tmp[16] = {5574, 1001, 307, 3, 0, 1, 1};
        for(int i = 0; i < 16; i++)
                cr_assert_eq(ace.nxs[i], tmp[i]);
}
