#include "ace.h"

static struct Ace *_alloc_ace();
static double *_alloc_xss_array(struct Ace *ace);
static void _read_first_line(struct Ace *ace, FILE *f);
static void _read_second_line(struct Ace *ace, FILE *f);
static void _read_iz_aw_array(struct Ace *ace, FILE *f);
static void _read_nxs_array(struct Ace *ace, FILE *f);
static void _read_jxs_array(struct Ace *ace, FILE *f);
static void _read_xss_array(struct Ace *ace, FILE *f, double *xss);
static void _read_esz_block(struct Ace *ace, double *xss);
static void _read_mtr_block(struct Ace *ace, double *xss);
static void _read_lqr_block(struct Ace *ace, double *xss);
static void _read_tyr_block(struct Ace *ace, double *xss);
static void _read_lsig_block(struct Ace *ace, double *xss);

struct Ace *new_ace(FILE *f)
{
        struct Ace *ace;
        ace = _alloc_ace();
        _read_first_line(ace, f);
        _read_second_line(ace, f);
        _read_iz_aw_array(ace, f);
        _read_nxs_array(ace, f);
        _read_jxs_array(ace, f);
        double *xss;
        xss = _alloc_xss_array(ace);
        _read_xss_array(ace, f, xss);
        _read_esz_block(ace, xss);
        _read_mtr_block(ace, xss);
        _read_lqr_block(ace, xss);
        _read_tyr_block(ace, xss);
        _read_lsig_block(ace, xss);
        free(xss);
        return ace;
}

static struct Ace *_alloc_ace()
{
        struct Ace *ptr;
        if ((ptr = malloc(sizeof *ptr)) == NULL)
                die("ace", "Allocation of ace failed");
        return ptr;
}

static void _read_first_line(struct Ace *ace, FILE *f)
{
        char dummy[MAX_STR];
        if (fgets(dummy, sizeof dummy, f) == NULL)
                die("ace", "Could not read first line");
        if (sscanf(dummy, "%11s %lf %lf %11s", ace->hz, &ace->aw, &ace->tz,
                   ace->hd) != 4)
                die("ace", "Could not parse first line");
}

static void _read_second_line(struct Ace *ace, FILE *f)
{
        if (fgets(ace->hk, 71, f) == NULL)
                die("ace", "Could not parse HK field");
        if (fgets(ace->hm, 11, f) == NULL)
                die("ace", "Could not parse HM field");
}

static void _read_iz_aw_array(struct Ace *ace, FILE *f)
{
        for (int i = 0; i < 16; i++) {
                if (fscanf(f, "%d", &ace->iz[i]) != 1)
                        die("ace", "Could not parse IZ[%d]", i);
                if (fscanf(f, "%lf", &ace->awr[i]) != 1)
                        die("ace", "Could not parse AW[%d]", i);
        }
}

static void _read_nxs_array(struct Ace *ace, FILE *f)
{
        for (int i = 0; i < 16; i++)
                if (fscanf(f, "%d", &ace->nxs[i]) != 1)
                        die("new_ace", "Could not parse NXS[%d]", i);
}

static void _read_jxs_array(struct Ace *ace, FILE *f)
{
        for (int i = 0; i < 32; i++)
                if (fscanf(f, "%d", &ace->jxs[i]) != 1)
                        die("new_ace", "Could not parse NXS[%d]", i);
}

static double *_alloc_xss_array(struct Ace *ace)
{
        int sz = ace->nxs[0];
        double *ptr;
        if ((ptr = malloc(sz * sizeof(double))) == NULL)
                die("ace", "Allocation of xss array failed");
        return ptr;
}

static void _read_xss_array(struct Ace *ace, FILE *f, double *xss)
{
        int sz = ace->nxs[0];
        if (sz < 1)
                die("ace", "Table size error %d (NXS[1]) <1", sz);
        for (int i = 0; i < sz; i++)
                fscanf(f, "%lf", (xss + i));
}

static void _read_esz_block(struct Ace *ace, double *xss)
{
        struct Esz *esz = &ace->esz;
        int loc         = ace->jxs[0] - 1;
        int ne          = ace->nxs[2];
        double *ptr     = xss + loc;
        /*energy grid*/
        if ((esz->egrid = malloc(ne * sizeof esz->egrid)) == NULL)
                die("new_ace", "Allocation of egrid failed");
        for (int i = 0; i < ne; i++)
                esz->egrid[i] = *ptr++;
        /* total cross section */
        if ((esz->xstot = malloc(ne * sizeof esz->xstot)) == NULL)
                die("new_ace", "Allocation of xstot failed");
        for (int i = 0; i < ne; i++)
                esz->xstot[i] = *ptr++;
        /* total neutron disappearance cross section */
        if ((esz->xsa = malloc(ne * sizeof esz->xsa)) == NULL)
                die("new_ace", "Allocation of xsa failed");
        for (int i = 0; i < ne; i++)
                esz->xsa[i] = *ptr++;
        /* elastic cross section */
        if ((esz->xsel = malloc(ne * sizeof esz->xsa)) == NULL)
                die("new_ace", "Allocation of xsel failed");
        for (int i = 0; i < ne; i++)
                esz->xsel[i] = *ptr++;
        /* average heating numbers */
        if ((esz->have = malloc(ne * sizeof esz->have)) == NULL)
                die("new_ace", "Allocation of have failed");
        for (int i = 0; i < ne; i++)
                esz->have[i] = *ptr++;
}

static void _read_mtr_block(struct Ace *ace, double *xss)
{
        struct Mtr *mtr = &ace->mtr;
        int loc         = ace->jxs[2] - 1;
        int nmt         = ace->nxs[3];
        double *ptr     = xss + loc;
        if ((mtr->mts = malloc(nmt * sizeof mtr->mts)) == NULL)
                die("new_ace", "Allocation of mts failed");
        for (int i = 0; i < nmt; i++)
                mtr->mts[i] = (int)*ptr++;
}

static void _read_lqr_block(struct Ace *ace, double *xss)
{
        struct Lqr *lqr = &ace->lqr;
        int loc         = ace->jxs[3] - 1;
        int nmt         = ace->nxs[3];
        double *ptr     = xss + loc;
        if ((lqr->qs = malloc(nmt * sizeof lqr->qs)) == NULL)
                die("new_ace", "Allocation of qs failed");
        for (int i = 0; i < nmt; i++)
                lqr->qs[i] = *ptr++;
}

static void _read_tyr_block(struct Ace *ace, double *xss)
{
        struct Tyr *tyr = &ace->tyr;
        int loc         = ace->jxs[4] - 1;
        int nmt         = ace->nxs[3];
        double *ptr     = xss + loc;
        if ((tyr->tys = malloc(nmt * sizeof tyr->tys)) == NULL)
                die("new_ace", "Allocation of tys failed");
        for (int i = 0; i < nmt; i++)
                tyr->tys[i] = (int)*ptr++;
}

static void _read_lsig_block(struct Ace *ace, double *xss)
{
        struct Lsig *lsig = &ace->lsig;
        int loc           = ace->jxs[5] - 1;
        int nmt           = ace->nxs[3];
        double *ptr       = xss + loc;
        if ((lsig->locas = malloc(nmt * sizeof lsig->locas)) == NULL)
                die("new_ace", "Allocation of locas failed");
        for (int i = 0; i < nmt; i++)
                lsig->locas[i] = (int)*ptr++;
}
