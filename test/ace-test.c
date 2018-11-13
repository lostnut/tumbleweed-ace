#include <criterion/criterion.h>
#include <stdio.h>
#include "../src/ace.h"


static FILE *f;
static struct Ace ace;
void setup(void) {
        if((f = fopen("test/resources/1-H-1g.jeff33.ACE", "r")) == NULL){
                printf("could not open resource file\n");
        }
        ace = new_ace(f);
}

void teardown(void) {
        fclose(f);
}

Test(suite_name, test_name, .init = setup, .fini = teardown) {
        cr_assert_str_eq(ace.hz, "1001.03c");
}
