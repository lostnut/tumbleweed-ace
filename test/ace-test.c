#include <stdio.h>
#include "../src/ace.h"
#include <criterion/criterion.h>

static FILE *f;
static struct Ace ace;
void setup(void)
{
        if ((f = fopen("test/resources/1-H-1g.jeff33.ACE", "r")) == NULL) {
                printf("could not open resource file\n");
        }
        ace = new_ace(f);
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
        cr_assert_str_eq(ace.hk, "MAT=125 ACE file produced at NEA with NDEC   "
                                 "                         ");
}

Test(ace, hm)
{
        cr_assert_str_eq(ace.hm, "   mat 125");
}

Test(ace, iz)
{
        int tmp[16] = {0};
        for (int i = 0; i < 16; i++)
                cr_assert_eq(ace.iz[i], tmp[i]);
}

Test(ace, awr)
{
        double tmp[16] = {0};
        for (int i = 0; i < 16; i++)
                cr_assert_eq(ace.awr[i], tmp[i]);
}

Test(ace, nxs)
{
        int tmp[16] = {5574, 1001, 307, 3, 0, 1, 1};
        for (int i = 0; i < 16; i++)
                cr_assert_eq(ace.nxs[i], tmp[i]);
}

Test(ace, jxs)
{
        int tmp[32] = {1,    0,    1536, 1539, 1542, 1545, 1548, 2475,
                       2476, 3890, 3890, 3890, 4197, 4198, 4199, 4207,
                       4208, 4208, 4209, 4892, 0,    4893, 0,    0,
                       0,    0,    0,    0,    0,    4894, 4895, 4896};
        for (int i = 0; i < 32; i++)
                cr_assert_eq(ace.jxs[i], tmp[i]);
}

Test(ace, egrid)
{
        double egrid[307] = {
                1.00000000000E-11, 1.06250000000E-11, 1.12500000000E-11,
                1.18750000000E-11, 1.25000000000E-11, 1.37500000000E-11,
                1.50000000000E-11, 1.62500000000E-11, 1.75000000000E-11,
                1.87500000000E-11, 2.00000000000E-11, 2.18750000000E-11,
                2.37500000000E-11, 2.56250000000E-11, 2.75000000000E-11,
                2.93750000000E-11, 3.12500000000E-11, 3.31250000000E-11,
                3.50000000000E-11, 3.87500000000E-11, 4.25000000000E-11,
                4.62500000000E-11, 5.00000000000E-11, 5.31250000000E-11,
                5.62500000000E-11, 5.93750000000E-11, 6.25000000000E-11,
                6.87500000000E-11, 7.50000000000E-11, 8.12500000000E-11,
                8.75000000000E-11, 9.37500000000E-11, 1.00000000000E-10,
                1.06250000000E-10, 1.12500000000E-10, 1.18750000000E-10,
                1.25000000000E-10, 1.37500000000E-10, 1.50000000000E-10,
                1.62500000000E-10, 1.75000000000E-10, 1.87500000000E-10,
                2.00000000000E-10, 2.18750000000E-10, 2.37500000000E-10,
                2.56250000000E-10, 2.75000000000E-10, 2.93750000000E-10,
                3.12500000000E-10, 3.31250000000E-10, 3.50000000000E-10,
                3.87500000000E-10, 4.25000000000E-10, 4.62500000000E-10,
                5.00000000000E-10, 5.31250000000E-10, 5.62500000000E-10,
                5.93750000000E-10, 6.25000000000E-10, 6.87500000000E-10,
                7.50000000000E-10, 8.12500000000E-10, 8.75000000000E-10,
                9.37500000000E-10, 1.00000000000E-09, 1.06250000000E-09,
                1.12500000000E-09, 1.18750000000E-09, 1.25000000000E-09,
                1.37500000000E-09, 1.50000000000E-09, 1.62500000000E-09,
                1.75000000000E-09, 1.87500000000E-09, 2.00000000000E-09,
                2.18750000000E-09, 2.37500000000E-09, 2.56250000000E-09,
                2.75000000000E-09, 2.93750000000E-09, 3.12500000000E-09,
                3.31250000000E-09, 3.50000000000E-09, 3.87500000000E-09,
                4.25000000000E-09, 4.62500000000E-09, 5.00000000000E-09,
                5.31250000000E-09, 5.62500000000E-09, 5.93750000000E-09,
                6.25000000000E-09, 6.87500000000E-09, 7.50000000000E-09,
                8.12500000000E-09, 8.75000000000E-09, 9.37500000000E-09,
                1.00000000000E-08, 1.06250000000E-08, 1.12500000000E-08,
                1.18750000000E-08, 1.25000000000E-08, 1.37500000000E-08,
                1.50000000000E-08, 1.62500000000E-08, 1.75000000000E-08,
                1.87500000000E-08, 2.00000000000E-08, 2.13250000000E-08,
                2.26500000000E-08, 2.39750000000E-08, 2.53000000000E-08,
                2.68437500000E-08, 2.83875000000E-08, 3.14750000000E-08,
                3.45625000000E-08, 3.76500000000E-08, 4.07375000000E-08,
                4.38250000000E-08, 4.69125000000E-08, 5.00000000000E-08,
                5.31250000000E-08, 5.62500000000E-08, 5.93750000000E-08,
                6.25000000000E-08, 6.87500000000E-08, 7.50000000000E-08,
                8.12500000000E-08, 8.75000000000E-08, 9.37500000000E-08,
                1.00000000000E-07, 1.06250000000E-07, 1.12500000000E-07,
                1.18750000000E-07, 1.25000000000E-07, 1.37500000000E-07,
                1.50000000000E-07, 1.62500000000E-07, 1.75000000000E-07,
                1.87500000000E-07, 2.00000000000E-07, 2.18750000000E-07,
                2.37500000000E-07, 2.56250000000E-07, 2.75000000000E-07,
                2.93750000000E-07, 3.12500000000E-07, 3.31250000000E-07,
                3.50000000000E-07, 3.87500000000E-07, 4.25000000000E-07,
                5.00000000000E-07, 6.25000000000E-07, 7.50000000000E-07,
                8.75000000000E-07, 1.00000000000E-06, 1.25000000000E-06,
                1.50000000000E-06, 1.75000000000E-06, 2.00000000000E-06,
                2.37500000000E-06, 2.75000000000E-06, 3.12500000000E-06,
                3.50000000000E-06, 4.25000000000E-06, 5.00000000000E-06,
                6.25000000000E-06, 7.50000000000E-06, 8.75000000000E-06,
                1.00000000000E-05, 1.25000000000E-05, 1.50000000000E-05,
                1.75000000000E-05, 2.00000000000E-05, 2.37500000000E-05,
                2.75000000000E-05, 3.12500000000E-05, 3.50000000000E-05,
                4.25000000000E-05, 5.00000000000E-05, 6.25000000000E-05,
                7.50000000000E-05, 8.75000000000E-05, 1.00000000000E-04,
                1.25000000000E-04, 1.50000000000E-04, 1.75000000000E-04,
                2.00000000000E-04, 2.37500000000E-04, 2.75000000000E-04,
                3.12500000000E-04, 3.50000000000E-04, 4.25000000000E-04,
                5.00000000000E-04, 6.25000000000E-04, 7.50000000000E-04,
                8.75000000000E-04, 1.00000000000E-03, 1.25000000000E-03,
                1.50000000000E-03, 1.75000000000E-03, 2.00000000000E-03,
                2.25000000000E-03, 2.50000000000E-03, 2.75000000000E-03,
                3.00000000000E-03, 3.25000000000E-03, 3.50000000000E-03,
                4.00000000000E-03, 4.50000000000E-03, 5.00000000000E-03,
                5.50000000000E-03, 6.00000000000E-03, 6.50000000000E-03,
                7.00000000000E-03, 8.00000000000E-03, 9.00000000000E-03,
                1.00000000000E-02, 1.25000000000E-02, 1.50000000000E-02,
                1.75000000000E-02, 2.00000000000E-02, 2.25000000000E-02,
                2.50000000000E-02, 2.75000000000E-02, 3.00000000000E-02,
                3.25000000000E-02, 3.50000000000E-02, 4.00000000000E-02,
                4.50000000000E-02, 5.00000000000E-02, 5.50000000000E-02,
                6.00000000000E-02, 6.50000000000E-02, 7.00000000000E-02,
                8.00000000000E-02, 9.00000000000E-02, 1.00000000000E-01,
                1.25000000000E-01, 1.50000000000E-01, 1.75000000000E-01,
                2.00000000000E-01, 2.25000000000E-01, 2.50000000000E-01,
                2.75000000000E-01, 3.00000000000E-01, 3.25000000000E-01,
                3.50000000000E-01, 4.00000000000E-01, 4.50000000000E-01,
                5.00000000000E-01, 5.50000000000E-01, 6.00000000000E-01,
                6.50000000000E-01, 7.00000000000E-01, 8.00000000000E-01,
                9.00000000000E-01, 1.00000000000E+00, 1.20000000000E+00,
                1.40000000000E+00, 1.60000000000E+00, 1.80000000000E+00,
                2.00000000000E+00, 2.20000000000E+00, 2.40000000000E+00,
                2.60000000000E+00, 2.80000000000E+00, 3.00000000000E+00,
                3.20000000000E+00, 3.40000000000E+00, 3.60000000000E+00,
                3.80000000000E+00, 4.00000000000E+00, 4.20000000000E+00,
                4.40000000000E+00, 4.60000000000E+00, 4.80000000000E+00,
                5.00000000000E+00, 5.50000000000E+00, 6.00000000000E+00,
                6.50000000000E+00, 7.00000000000E+00, 7.50000000000E+00,
                8.00000000000E+00, 8.50000000000E+00, 9.00000000000E+00,
                9.50000000000E+00, 1.00000000000E+01, 1.05000000000E+01,
                1.10000000000E+01, 1.15000000000E+01, 1.20000000000E+01,
                1.25000000000E+01, 1.30000000000E+01, 1.35000000000E+01,
                1.40000000000E+01, 1.45000000000E+01, 1.50000000000E+01,
                1.55000000000E+01, 1.60000000000E+01, 1.65000000000E+01,
                1.70000000000E+01, 1.75000000000E+01, 1.80000000000E+01,
                1.85000000000E+01, 1.90000000000E+01, 1.95000000000E+01,
                2.00000000000E+01};
        cr_assert_arr_eq(ace.esz.egrid, egrid, 307);
}

Test(ace, xstot)
{
        double xs[307] = {
                1.17724876000E+03, 1.14210897000E+03, 1.10993934000E+03,
                1.08034426000E+03, 1.05299809000E+03, 1.00401022000E+03,
                9.61282200000E+02, 9.23585080000E+02, 8.90003270000E+02,
                8.59838760000E+02, 8.32548860000E+02, 7.96088260000E+02,
                7.64036330000E+02, 7.35570810000E+02, 7.10069050000E+02,
                6.87050343000E+02, 6.66136206000E+02, 6.47024451000E+02,
                6.29470205000E+02, 5.98266235000E+02, 5.71290484000E+02,
                5.47667121000E+02, 5.26754943000E+02, 5.11048077000E+02,
                4.96669567000E+02, 4.83442300000E+02, 4.71220304000E+02,
                4.49327327000E+02, 4.30232981000E+02, 4.13387969000E+02,
                3.98382878000E+02, 3.84905579000E+02, 3.72713425000E+02,
                3.61614393000E+02, 3.51454396000E+02, 3.42108353000E+02,
                3.33472903000E+02, 3.18005409000E+02, 3.04516209000E+02,
                2.92616989000E+02, 2.82018441000E+02, 2.72499730000E+02,
                2.63889523000E+02, 2.52387843000E+02, 2.42279251000E+02,
                2.33303456000E+02, 2.25263965000E+02, 2.18008918000E+02,
                2.11418519000E+02, 2.05397509000E+02, 1.99868290000E+02,
                1.90042979000E+02, 1.81552748000E+02, 1.74120865000E+02,
                1.67544752000E+02, 1.62607512000E+02, 1.58089435000E+02,
                1.53934626000E+02, 1.50097031000E+02, 1.43226391000E+02,
                1.37238516000E+02, 1.31959738000E+02, 1.27260921000E+02,
                1.23043664000E+02, 1.19231276000E+02, 1.15763197000E+02,
                1.12590834000E+02, 1.09674726000E+02, 1.06982209000E+02,
                1.02164672000E+02, 9.79694200000E+01, 9.42739380000E+01,
                9.09870770000E+01, 8.80393360000E+01, 8.53767360000E+01,
                8.18262960000E+01, 7.87124730000E+01, 7.59535510000E+01,
                7.34876850000E+01, 7.12671043000E+01, 6.92542506000E+01,
                6.74191451000E+01, 6.57375104000E+01, 6.27585235000E+01,
                6.01950784000E+01, 5.79605120000E+01, 5.59914743000E+01,
                5.45187276000E+01, 5.31756466000E+01, 5.19447398000E+01,
                5.08116803000E+01, 4.87932726000E+01, 4.70459679000E+01,
                4.55158567000E+01, 4.41628676000E+01, 4.29564776000E+01,
                4.18730023000E+01, 4.08937391000E+01, 4.00037293000E+01,
                3.91907950000E+01, 3.84449600000E+01, 3.71227906000E+01,
                3.59855606000E+01, 3.49959386000E+01, 3.41262537000E+01,
                3.33554627000E+01, 3.26672718000E+01, 3.20137306000E+01,
                3.14264599000E+01, 3.08957523000E+01, 3.04137180000E+01,
                2.99049665000E+01, 2.94452067000E+01, 2.86467714000E+01,
                2.79771702000E+01, 2.74075697000E+01, 2.69172092000E+01,
                2.64907110000E+01, 2.61164356000E+01, 2.57854250000E+01,
                2.54872611000E+01, 2.52204435000E+01, 2.49803227000E+01,
                2.47631132000E+01, 2.43855693000E+01, 2.40688019000E+01,
                2.37993243000E+01, 2.35673727000E+01, 2.33656671000E+01,
                2.31886685000E+01, 2.30321407000E+01, 2.28927345000E+01,
                2.27677938000E+01, 2.26551722000E+01, 2.24602887000E+01,
                2.22975337000E+01, 2.21595527000E+01, 2.20410759000E+01,
                2.19382442000E+01, 2.18481305000E+01, 2.17320651000E+01,
                2.16341355000E+01, 2.15503851000E+01, 2.14779155000E+01,
                2.14145885000E+01, 2.13587701000E+01, 2.13091877000E+01,
                2.12648462000E+01, 2.11888775000E+01, 2.11261186000E+01,
                2.10284662000E+01, 2.09170700000E+01, 2.08422291000E+01,
                2.07884057000E+01, 2.07477779000E+01, 2.06904148000E+01,
                2.06517647000E+01, 2.06238869000E+01, 2.06027899000E+01,
                2.05792387000E+01, 2.05619174000E+01, 2.05486000000E+01,
                2.05380280000E+01, 2.05222593000E+01, 2.05110313000E+01,
                2.04980163000E+01, 2.04891112000E+01, 2.04825851000E+01,
                2.04775648000E+01, 2.04702849000E+01, 2.04651999000E+01,
                2.04613815000E+01, 2.04583862000E+01, 2.04548634000E+01,
                2.04521091000E+01, 2.04498526000E+01, 2.04479302000E+01,
                2.04447920000E+01, 2.04422399000E+01, 2.04387306000E+01,
                2.04357770000E+01, 2.04331550000E+01, 2.04307407000E+01,
                2.04263012000E+01, 2.04221785000E+01, 2.04182586000E+01,
                2.04144506000E+01, 2.04089220000E+01, 2.04035093000E+01,
                2.03981713000E+01, 2.03928962000E+01, 2.03824643000E+01,
                2.03721240000E+01, 2.03551231000E+01, 2.03382280000E+01,
                2.03213944000E+01, 2.03045987000E+01, 2.02714602000E+01,
                2.02383787000E+01, 2.02053468000E+01, 2.01723447000E+01,
                2.01400656000E+01, 2.01077971000E+01, 2.00755470000E+01,
                2.00433133000E+01, 2.00110649000E+01, 1.99788307000E+01,
                1.99144124000E+01, 1.98518029000E+01, 1.97892312000E+01,
                1.97266655000E+01, 1.96641244000E+01, 1.96033164000E+01,
                1.95425416000E+01, 1.94210093000E+01, 1.93028337000E+01,
                1.91847439000E+01, 1.89033222000E+01, 1.86220408000E+01,
                1.83589895000E+01, 1.80961984000E+01, 1.78709633000E+01,
                1.76459383000E+01, 1.74209033000E+01, 1.71958783000E+01,
                1.69708433000E+01, 1.67458083000E+01, 1.62960783000E+01,
                1.59386750000E+01, 1.55815917000E+01, 1.52245184000E+01,
                1.48677251000E+01, 1.45770673000E+01, 1.42866996000E+01,
                1.37062041000E+01, 1.32241739000E+01, 1.27427238000E+01,
                1.18329391000E+01, 1.09238445000E+01, 1.02833569000E+01,
                9.64358528000E+00, 9.22042561000E+00, 8.79761494000E+00,
                8.37480327000E+00, 7.95229561000E+00, 7.68310802000E+00,
                7.41422244000E+00, 6.87663428000E+00, 6.50096578000E+00,
                6.12560229000E+00, 5.84619659000E+00, 5.56699890000E+00,
                5.34947862000E+00, 5.13210634000E+00, 4.78165124000E+00,
                4.49154240000E+00, 4.24618070000E+00, 3.85053146000E+00,
                3.54181422000E+00, 3.29137287000E+00, 3.08224139000E+00,
                2.90369677000E+00, 2.74858002000E+00, 2.61195516000E+00,
                2.49023421000E+00, 2.38077320000E+00, 2.28155813000E+00,
                2.19103001000E+00, 2.10795386000E+00, 2.03133769000E+00,
                1.96037050000E+00, 1.89438531000E+00, 1.83282310000E+00,
                1.77521289000E+00, 1.72115368000E+00, 1.67029947000E+00,
                1.62235327000E+00, 1.51358777000E+00, 1.41819131000E+00,
                1.33374287000E+00, 1.25840048000E+00, 1.19073011000E+00,
                1.12959677000E+00, 1.07408446000E+00, 1.02344716000E+00,
                9.77066588000E-01, 9.34429025000E-01, 8.95099875000E-01,
                8.58710735000E-01, 8.24946302000E-01, 7.93535076000E-01,
                7.64241754000E-01, 7.36861535000E-01, 7.11214819000E-01,
                6.87143905000E-01, 6.64509492000E-01, 6.43187979000E-01,
                6.23069267000E-01, 6.04055154000E-01, 5.86057740000E-01,
                5.68997726000E-01, 5.52804011000E-01, 5.37412095000E-01,
                5.22763779000E-01, 5.08805961000E-01, 4.95490443000E-01,
                4.82773424000E-01};
        cr_assert_arr_eq(xs, ace.esz.xstot, 307);
}

Test(ace, xsa)
{
        double xs[307] = {
                1.67057600000E+01, 1.62069700000E+01, 1.57503400000E+01,
                1.53302600000E+01, 1.49420900000E+01, 1.42467200000E+01,
                1.36402000000E+01, 1.31050800000E+01, 1.26283700000E+01,
                1.22001600000E+01, 1.18127600000E+01, 1.12951600000E+01,
                1.08401300000E+01, 1.04360100000E+01, 1.00739500000E+01,
                9.74714300000E+00, 9.45020600000E+00, 9.17885100000E+00,
                8.92960500000E+00, 8.48653500000E+00, 8.10348400000E+00,
                7.76802100000E+00, 7.47104300000E+00, 7.24797700000E+00,
                7.04376700000E+00, 6.85590000000E+00, 6.68230400000E+00,
                6.37132700000E+00, 6.10008100000E+00, 5.86076900000E+00,
                5.64757800000E+00, 5.45607900000E+00, 5.28282500000E+00,
                5.12509300000E+00, 4.98069600000E+00, 4.84785300000E+00,
                4.72510300000E+00, 4.50520900000E+00, 4.31340900000E+00,
                4.14418900000E+00, 3.99344100000E+00, 3.85803000000E+00,
                3.73552300000E+00, 3.57184300000E+00, 3.42795100000E+00,
                3.30015600000E+00, 3.18566500000E+00, 3.08231800000E+00,
                2.98841900000E+00, 2.90260900000E+00, 2.82379000000E+00,
                2.68367900000E+00, 2.56254800000E+00, 2.45646500000E+00,
                2.36255200000E+00, 2.29201200000E+00, 2.22743500000E+00,
                2.16802600000E+00, 2.11313100000E+00, 2.01479100000E+00,
                1.92901600000E+00, 1.85333800000E+00, 1.78592100000E+00,
                1.72536400000E+00, 1.67057600000E+00, 1.62069700000E+00,
                1.57503400000E+00, 1.53302600000E+00, 1.49420900000E+00,
                1.42467200000E+00, 1.36402000000E+00, 1.31050800000E+00,
                1.26283700000E+00, 1.22001600000E+00, 1.18127600000E+00,
                1.12951600000E+00, 1.08401300000E+00, 1.04360100000E+00,
                1.00739500000E+00, 9.74714300000E-01, 9.45020600000E-01,
                9.17885100000E-01, 8.92960400000E-01, 8.48653500000E-01,
                8.10348400000E-01, 7.76802000000E-01, 7.47104300000E-01,
                7.24797600000E-01, 7.04376600000E-01, 6.85589800000E-01,
                6.68230300000E-01, 6.37132600000E-01, 6.10007900000E-01,
                5.86076700000E-01, 5.64757600000E-01, 5.45607600000E-01,
                5.28282300000E-01, 5.12509100000E-01, 4.98069300000E-01,
                4.84785000000E-01, 4.72510000000E-01, 4.50520600000E-01,
                4.31340600000E-01, 4.14418600000E-01, 3.99343700000E-01,
                3.85802700000E-01, 3.73551800000E-01, 3.61760600000E-01,
                3.51019900000E-01, 3.41182300000E-01, 3.32128000000E-01,
                3.22436500000E-01, 3.13546700000E-01, 2.97771400000E-01,
                2.84160200000E-01, 2.72259700000E-01, 2.61739200000E-01,
                2.52351000000E-01, 2.43905600000E-01, 2.36255000000E-01,
                2.29201100000E-01, 2.22743500000E-01, 2.16802700000E-01,
                2.11313200000E-01, 2.01479300000E-01, 1.92901900000E-01,
                1.85334300000E-01, 1.78592700000E-01, 1.72537100000E-01,
                1.67058500000E-01, 1.62070700000E-01, 1.57504500000E-01,
                1.53303800000E-01, 1.49422200000E-01, 1.42468700000E-01,
                1.36403700000E-01, 1.31052700000E-01, 1.26285900000E-01,
                1.22004200000E-01, 1.18130500000E-01, 1.12955100000E-01,
                1.08405500000E-01, 1.04365100000E-01, 1.00745500000E-01,
                9.74784600000E-02, 9.45101300000E-02, 9.17976500000E-02,
                8.93062400000E-02, 8.48774800000E-02, 8.10485800000E-02,
                7.47261900000E-02, 6.68399600000E-02, 6.10190900000E-02,
                5.64956800000E-02, 5.28479400000E-02, 4.72647600000E-02,
                4.31446500000E-02, 3.99469100000E-02, 3.73699200000E-02,
                3.42987200000E-02, 3.18774300000E-02, 2.99000300000E-02,
                2.82480300000E-02, 2.56292900000E-02, 2.36313400000E-02,
                2.11362600000E-02, 1.92911500000E-02, 1.78651400000E-02,
                1.67148100000E-02, 1.49449100000E-02, 1.36399100000E-02,
                1.26315000000E-02, 1.18161700000E-02, 1.08433600000E-02,
                1.00791200000E-02, 9.45263600000E-03, 8.93021900000E-03,
                8.10196300000E-03, 7.46993200000E-03, 6.68056300000E-03,
                6.09698400000E-03, 5.64498600000E-03, 5.28073400000E-03,
                4.72121700000E-03, 4.30854600000E-03, 3.98863700000E-03,
                3.73060000000E-03, 3.42201500000E-03, 3.17933000000E-03,
                2.98132900000E-03, 2.81617200000E-03, 2.55426700000E-03,
                2.35403800000E-03, 2.10314700000E-03, 1.91802300000E-03,
                1.77442000000E-03, 1.65874700000E-03, 1.48023200000E-03,
                1.34873800000E-03, 1.24679100000E-03, 1.16472200000E-03,
                1.09555000000E-03, 1.03714600000E-03, 9.87003300000E-04,
                9.43348500000E-04, 9.04898500000E-04, 8.70730700000E-04,
                8.12352800000E-04, 7.62908600000E-04, 7.21223300000E-04,
                6.85481500000E-04, 6.54392900000E-04, 6.26420200000E-04,
                6.01596600000E-04, 5.59307500000E-04, 5.23721400000E-04,
                4.93851200000E-04, 4.42224700000E-04, 3.90771200000E-04,
                3.59493400000E-04, 3.28387200000E-04, 3.13300300000E-04,
                2.98295400000E-04, 2.83290500000E-04, 2.68285600000E-04,
                2.53280700000E-04, 2.38275800000E-04, 2.08326100000E-04,
                1.94964800000E-04, 1.81663500000E-04, 1.68362100000E-04,
                1.55085200000E-04, 1.47323700000E-04, 1.39586600000E-04,
                1.24126000000E-04, 1.13943300000E-04, 1.03786200000E-04,
                8.91408600000E-05, 7.45175200000E-05, 6.68928600000E-05,
                5.92842800000E-05, 5.56093500000E-05, 5.19407500000E-05,
                4.82721600000E-05, 4.46076700000E-05, 4.30213700000E-05,
                4.14391700000E-05, 3.82766600000E-05, 3.67826000000E-05,
                3.52914400000E-05, 3.45947400000E-05, 3.38996200000E-05,
                3.36205400000E-05, 3.33423900000E-05, 3.32443400000E-05,
                3.34022300000E-05, 3.36990500000E-05, 3.44554600000E-05,
                3.52169900000E-05, 3.58729500000E-05, 3.63894900000E-05,
                3.67662300000E-05, 3.70169300000E-05, 3.71599300000E-05,
                3.72143500000E-05, 3.71977300000E-05, 3.71253900000E-05,
                3.70102300000E-05, 3.68628900000E-05, 3.66920300000E-05,
                3.65045700000E-05, 3.63060000000E-05, 3.61006300000E-05,
                3.58918300000E-05, 3.56821800000E-05, 3.54736400000E-05,
                3.52676900000E-05, 3.47704900000E-05, 3.43050600000E-05,
                3.38741800000E-05, 3.34769900000E-05, 3.31108400000E-05,
                3.27723300000E-05, 3.24578800000E-05, 3.21640000000E-05,
                3.18874900000E-05, 3.16254500000E-05, 3.13753100000E-05,
                3.11348500000E-05, 3.09021400000E-05, 3.06755200000E-05,
                3.04536000000E-05, 3.02351800000E-05, 3.00192800000E-05,
                2.98050700000E-05, 2.95919000000E-05, 2.93792000000E-05,
                2.91665600000E-05, 2.89536300000E-05, 2.87401800000E-05,
                2.85260300000E-05, 2.83110700000E-05, 2.80952300000E-05,
                2.78785100000E-05, 2.76609500000E-05, 2.74425900000E-05,
                2.72235400000E-05};
        cr_assert_arr_eq(ace.esz.xsa, xs, 307);
}

Test(ace, xsel)
{
        double xs[307] = {
                1.16054300000E+03, 1.12590200000E+03, 1.09418900000E+03,
                1.06501400000E+03, 1.03805600000E+03, 9.89763500000E+02,
                9.47642000000E+02, 9.10480000000E+02, 8.77374900000E+02,
                8.47638600000E+02, 8.20736100000E+02, 7.84793100000E+02,
                7.53196200000E+02, 7.25134800000E+02, 6.99995100000E+02,
                6.77303200000E+02, 6.56686000000E+02, 6.37845600000E+02,
                6.20540600000E+02, 5.89779700000E+02, 5.63187000000E+02,
                5.39899100000E+02, 5.19283900000E+02, 5.03800100000E+02,
                4.89625800000E+02, 4.76586400000E+02, 4.64538000000E+02,
                4.42956000000E+02, 4.24132900000E+02, 4.07527200000E+02,
                3.92735300000E+02, 3.79449500000E+02, 3.67430600000E+02,
                3.56489300000E+02, 3.46473700000E+02, 3.37260500000E+02,
                3.28747800000E+02, 3.13500200000E+02, 3.00202800000E+02,
                2.88472800000E+02, 2.78025000000E+02, 2.68641700000E+02,
                2.60154000000E+02, 2.48816000000E+02, 2.38851300000E+02,
                2.30003300000E+02, 2.22078300000E+02, 2.14926600000E+02,
                2.08430100000E+02, 2.02494900000E+02, 1.97044500000E+02,
                1.87359300000E+02, 1.78990200000E+02, 1.71664400000E+02,
                1.65182200000E+02, 1.60315500000E+02, 1.55862000000E+02,
                1.51766600000E+02, 1.47983900000E+02, 1.41211600000E+02,
                1.35309500000E+02, 1.30106400000E+02, 1.25475000000E+02,
                1.21318300000E+02, 1.17560700000E+02, 1.14142500000E+02,
                1.11015800000E+02, 1.08141700000E+02, 1.05488000000E+02,
                1.00740000000E+02, 9.66054000000E+01, 9.29634300000E+01,
                8.97242400000E+01, 8.68193200000E+01, 8.41954600000E+01,
                8.06967800000E+01, 7.76284600000E+01, 7.49099500000E+01,
                7.24802900000E+01, 7.02923900000E+01, 6.83092300000E+01,
                6.65012600000E+01, 6.48445500000E+01, 6.19098700000E+01,
                5.93847300000E+01, 5.71837100000E+01, 5.52443700000E+01,
                5.37939300000E+01, 5.24712700000E+01, 5.12591500000E+01,
                5.01434500000E+01, 4.81561400000E+01, 4.64359600000E+01,
                4.49297800000E+01, 4.35981100000E+01, 4.24108700000E+01,
                4.13447200000E+01, 4.03812300000E+01, 3.95056600000E+01,
                3.87060100000E+01, 3.79724500000E+01, 3.66722700000E+01,
                3.55542200000E+01, 3.45815200000E+01, 3.37269100000E+01,
                3.29696600000E+01, 3.22937200000E+01, 3.16519700000E+01,
                3.10754400000E+01, 3.05545700000E+01, 3.00815900000E+01,
                2.95825300000E+01, 2.91316600000E+01, 2.83490000000E+01,
                2.76930100000E+01, 2.71353100000E+01, 2.66554700000E+01,
                2.62383600000E+01, 2.58725300000E+01, 2.55491700000E+01,
                2.52580600000E+01, 2.49977000000E+01, 2.47635200000E+01,
                2.45518000000E+01, 2.41840900000E+01, 2.38759000000E+01,
                2.36139900000E+01, 2.33887800000E+01, 2.31931300000E+01,
                2.30216100000E+01, 2.28700700000E+01, 2.27352300000E+01,
                2.26144900000E+01, 2.25057500000E+01, 2.23178200000E+01,
                2.21611300000E+01, 2.20285000000E+01, 2.19147900000E+01,
                2.18162400000E+01, 2.17300000000E+01, 2.16191100000E+01,
                2.15257300000E+01, 2.14460200000E+01, 2.13771700000E+01,
                2.13171100000E+01, 2.12642600000E+01, 2.12173900000E+01,
                2.11755400000E+01, 2.11040000000E+01, 2.10450700000E+01,
                2.09537400000E+01, 2.08502300000E+01, 2.07812100000E+01,
                2.07319100000E+01, 2.06949300000E+01, 2.06431500000E+01,
                2.06086200000E+01, 2.05839400000E+01, 2.05654200000E+01,
                2.05449400000E+01, 2.05300400000E+01, 2.05187000000E+01,
                2.05097800000E+01, 2.04966300000E+01, 2.04874000000E+01,
                2.04768800000E+01, 2.04698200000E+01, 2.04647200000E+01,
                2.04608500000E+01, 2.04553400000E+01, 2.04515600000E+01,
                2.04487500000E+01, 2.04465700000E+01, 2.04440200000E+01,
                2.04420300000E+01, 2.04404000000E+01, 2.04390000000E+01,
                2.04366900000E+01, 2.04347700000E+01, 2.04320500000E+01,
                2.04296800000E+01, 2.04275100000E+01, 2.04254600000E+01,
                2.04215800000E+01, 2.04178700000E+01, 2.04142700000E+01,
                2.04107200000E+01, 2.04055000000E+01, 2.04003300000E+01,
                2.03951900000E+01, 2.03900800000E+01, 2.03799100000E+01,
                2.03697700000E+01, 2.03530200000E+01, 2.03363100000E+01,
                2.03196200000E+01, 2.03029400000E+01, 2.02699800000E+01,
                2.02370300000E+01, 2.02041000000E+01, 2.01711800000E+01,
                2.01389700000E+01, 2.01067600000E+01, 2.00745600000E+01,
                2.00423700000E+01, 2.00101600000E+01, 1.99779600000E+01,
                1.99136000000E+01, 1.98510400000E+01, 1.97885100000E+01,
                1.97259800000E+01, 1.96634700000E+01, 1.96026900000E+01,
                1.95419400000E+01, 1.94204500000E+01, 1.93023100000E+01,
                1.91842500000E+01, 1.89028800000E+01, 1.86216500000E+01,
                1.83586300000E+01, 1.80958700000E+01, 1.78706500000E+01,
                1.76456400000E+01, 1.74206200000E+01, 1.71956100000E+01,
                1.69705900000E+01, 1.67455700000E+01, 1.62958700000E+01,
                1.59384800000E+01, 1.55814100000E+01, 1.52243500000E+01,
                1.48675700000E+01, 1.45769200000E+01, 1.42865600000E+01,
                1.37060800000E+01, 1.32240600000E+01, 1.27426200000E+01,
                1.18328500000E+01, 1.09237700000E+01, 1.02832900000E+01,
                9.64352600000E+00, 9.22037000000E+00, 8.79756300000E+00,
                8.37475500000E+00, 7.95225100000E+00, 7.68306500000E+00,
                7.41418100000E+00, 6.87659600000E+00, 6.50092900000E+00,
                6.12556700000E+00, 5.84616200000E+00, 5.56696500000E+00,
                5.34944500000E+00, 5.13207300000E+00, 4.78161800000E+00,
                4.49150900000E+00, 4.24614700000E+00, 3.85049700000E+00,
                3.54177900000E+00, 3.29133700000E+00, 3.08220500000E+00,
                2.90366000000E+00, 2.74854300000E+00, 2.61191800000E+00,
                2.49019700000E+00, 2.38073600000E+00, 2.28152100000E+00,
                2.19099300000E+00, 2.10791700000E+00, 2.03130100000E+00,
                1.96033400000E+00, 1.89434900000E+00, 1.83278700000E+00,
                1.77517700000E+00, 1.72111800000E+00, 1.67026400000E+00,
                1.62231800000E+00, 1.51355300000E+00, 1.41815700000E+00,
                1.33370900000E+00, 1.25836700000E+00, 1.19069700000E+00,
                1.12956400000E+00, 1.07405200000E+00, 1.02341500000E+00,
                9.77034700000E-01, 9.34397400000E-01, 8.95068500000E-01,
                8.58679600000E-01, 8.24915400000E-01, 7.93504400000E-01,
                7.64211300000E-01, 7.36831300000E-01, 7.11184800000E-01,
                6.87114100000E-01, 6.64479900000E-01, 6.43158600000E-01,
                6.23040100000E-01, 6.04026200000E-01, 5.86029000000E-01,
                5.68969200000E-01, 5.52775700000E-01, 5.37384000000E-01,
                5.22735900000E-01, 5.08778300000E-01, 4.95463000000E-01,
                4.82746200000E-01};
        cr_assert_arr_eq(ace.esz.xsel, xs, 307);
}

Test(ace, have)
{
        double heat[307] = {
                1.86718700000E-05, 1.86717200000E-05, 1.86715600000E-05,
                1.86714200000E-05, 1.86712700000E-05, 1.86709700000E-05,
                1.86706700000E-05, 1.86703600000E-05, 1.86700700000E-05,
                1.86697600000E-05, 1.86694600000E-05, 1.86690100000E-05,
                1.86685500000E-05, 1.86681000000E-05, 1.86676400000E-05,
                1.86671900000E-05, 1.86667400000E-05, 1.86662800000E-05,
                1.86658400000E-05, 1.86649200000E-05, 1.86640300000E-05,
                1.86631100000E-05, 1.86622100000E-05, 1.86614600000E-05,
                1.86607000000E-05, 1.86599500000E-05, 1.86591900000E-05,
                1.86576800000E-05, 1.86561800000E-05, 1.86546700000E-05,
                1.86531600000E-05, 1.86516600000E-05, 1.86501500000E-05,
                1.86486400000E-05, 1.86471400000E-05, 1.86456300000E-05,
                1.86441300000E-05, 1.86411200000E-05, 1.86381100000E-05,
                1.86351000000E-05, 1.86320900000E-05, 1.86290900000E-05,
                1.86260800000E-05, 1.86215700000E-05, 1.86170600000E-05,
                1.86125600000E-05, 1.86080800000E-05, 1.86035800000E-05,
                1.85991000000E-05, 1.85946100000E-05, 1.85901300000E-05,
                1.85811800000E-05, 1.85722300000E-05, 1.85633000000E-05,
                1.85543700000E-05, 1.85469500000E-05, 1.85395200000E-05,
                1.85321100000E-05, 1.85247200000E-05, 1.85099300000E-05,
                1.84951800000E-05, 1.84804600000E-05, 1.84657600000E-05,
                1.84511100000E-05, 1.84364600000E-05, 1.84218700000E-05,
                1.84073000000E-05, 1.83927600000E-05, 1.83782600000E-05,
                1.83493400000E-05, 1.83205200000E-05, 1.82918300000E-05,
                1.82632600000E-05, 1.82348000000E-05, 1.82064600000E-05,
                1.81641700000E-05, 1.81221300000E-05, 1.80803500000E-05,
                1.80388200000E-05, 1.79975600000E-05, 1.79565300000E-05,
                1.79157600000E-05, 1.78752100000E-05, 1.77948700000E-05,
                1.77154700000E-05, 1.76370100000E-05, 1.75594600000E-05,
                1.74955200000E-05, 1.74322000000E-05, 1.73694800000E-05,
                1.73073600000E-05, 1.71848900000E-05, 1.70646900000E-05,
                1.69467200000E-05, 1.68309100000E-05, 1.67171900000E-05,
                1.66055300000E-05, 1.64958400000E-05, 1.63880900000E-05,
                1.62822100000E-05, 1.61781600000E-05, 1.59753700000E-05,
                1.57793200000E-05, 1.55897000000E-05, 1.54061700000E-05,
                1.52284500000E-05, 1.50562300000E-05, 1.48794200000E-05,
                1.47082400000E-05, 1.45423900000E-05, 1.43816300000E-05,
                1.42004300000E-05, 1.40254600000E-05, 1.36929400000E-05,
                1.33816800000E-05, 1.30896400000E-05, 1.28150200000E-05,
                1.25562500000E-05, 1.23119300000E-05, 1.20808200000E-05,
                1.18592500000E-05, 1.16490900000E-05, 1.14494400000E-05,
                1.12594800000E-05, 1.09058200000E-05, 1.05831200000E-05,
                1.02872500000E-05, 1.00148300000E-05, 9.76302500000E-06,
                9.52943900000E-06, 9.31203900000E-06, 9.10909500000E-06,
                8.91913400000E-06, 8.74086100000E-06, 8.41505200000E-06,
                8.12432000000E-06, 7.86295700000E-06, 7.62647000000E-06,
                7.41124900000E-06, 7.21438800000E-06, 6.94841000000E-06,
                6.71203200000E-06, 6.50033400000E-06, 6.30946200000E-06,
                6.13635000000E-06, 5.97851400000E-06, 5.83394800000E-06,
                5.70098200000E-06, 5.46452300000E-06, 5.26045500000E-06,
                4.92579000000E-06, 4.51710500000E-06, 4.22722300000E-06,
                4.01338900000E-06, 3.85155600000E-06, 3.63078700000E-06,
                3.49890500000E-06, 3.42360600000E-06, 3.38663600000E-06,
                3.38050000000E-06, 3.41490400000E-06, 3.47710600000E-06,
                3.55975400000E-06, 3.76824200000E-06, 4.01597100000E-06,
                4.48177100000E-06, 4.98886900000E-06, 5.52265700000E-06,
                6.07402300000E-06, 7.21063700000E-06, 8.37697200000E-06,
                9.56228700000E-06, 1.07599700000E-05, 1.25725200000E-05,
                1.43984500000E-05, 1.62332100000E-05, 1.80746500000E-05,
                2.17714300000E-05, 2.54808200000E-05, 3.16800800000E-05,
                3.78925700000E-05, 4.41135200000E-05, 5.03401200000E-05,
                6.28041300000E-05, 7.52776200000E-05, 8.77570400000E-05,
                1.00240500000E-04, 1.18970700000E-04, 1.37705100000E-04,
                1.56442400000E-04, 1.75181800000E-04, 2.12665000000E-04,
                2.50152200000E-04, 3.12636200000E-04, 3.75124500000E-04,
                4.37615400000E-04, 5.00108400000E-04, 6.25097100000E-04,
                7.50089200000E-04, 8.75083700000E-04, 1.00007900000E-03,
                1.12507500000E-03, 1.25007300000E-03, 1.37507000000E-03,
                1.50006900000E-03, 1.62506700000E-03, 1.75006700000E-03,
                2.00006600000E-03, 2.25006600000E-03, 2.50006700000E-03,
                2.75006900000E-03, 3.00007200000E-03, 3.25007500000E-03,
                3.50007900000E-03, 4.00008800000E-03, 4.50009900000E-03,
                5.00011200000E-03, 6.25015000000E-03, 7.50020400000E-03,
                8.75026400000E-03, 1.00003300000E-02, 1.12504100000E-02,
                1.25005000000E-02, 1.37506000000E-02, 1.50007000000E-02,
                1.62508200000E-02, 1.75009400000E-02, 2.00012200000E-02,
                2.25015200000E-02, 2.50018600000E-02, 2.75022300000E-02,
                3.00026400000E-02, 3.25030700000E-02, 3.50035300000E-02,
                4.00045600000E-02, 4.50056800000E-02, 5.00069200000E-02,
                6.25104000000E-02, 7.50145900000E-02, 8.75191900000E-02,
                1.00024400000E-01, 1.12529800000E-01, 1.25035800000E-01,
                1.37542300000E-01, 1.50049400000E-01, 1.62556400000E-01,
                1.75063800000E-01, 2.00080000000E-01, 2.25097000000E-01,
                2.50115500000E-01, 2.75134900000E-01, 3.00155600000E-01,
                3.25177500000E-01, 3.50200500000E-01, 4.00250200000E-01,
                4.50305400000E-01, 5.00366600000E-01, 6.00508500000E-01,
                7.00681000000E-01, 8.00888300000E-01, 9.01134500000E-01,
                1.00142400000E+00, 1.10175900000E+00, 1.20214500000E+00,
                1.30258200000E+00, 1.40307400000E+00, 1.50362300000E+00,
                1.60423000000E+00, 1.70489700000E+00, 1.80562500000E+00,
                1.90641400000E+00, 2.00726500000E+00, 2.10817800000E+00,
                2.20915400000E+00, 2.31019100000E+00, 2.41129100000E+00,
                2.51245200000E+00, 2.76561900000E+00, 3.01915100000E+00,
                3.27303000000E+00, 3.52723200000E+00, 3.78173100000E+00,
                4.03650100000E+00, 4.29150900000E+00, 4.54672500000E+00,
                4.80211900000E+00, 5.05765800000E+00, 5.31330900000E+00,
                5.56904300000E+00, 5.82482900000E+00, 6.08063700000E+00,
                6.33644100000E+00, 6.59221500000E+00, 6.84793700000E+00,
                7.10358200000E+00, 7.35913200000E+00, 7.61457000000E+00,
                7.86988300000E+00, 8.12505600000E+00, 8.38008000000E+00,
                8.63495000000E+00, 8.88966100000E+00, 9.14420800000E+00,
                9.39859700000E+00, 9.65282700000E+00, 9.90690800000E+00,
                1.01608500000E+01};
        cr_assert_arr_eq(ace.esz.have, heat, 307);
}
