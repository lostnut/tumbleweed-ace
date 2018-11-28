#include "ace.h"

struct Ace new_ace(FILE *f)
{
        struct Ace ace;
        char dummy[MAX_STR];
        /* Read first line */
        if (fgets(dummy, sizeof dummy, f) == NULL)
                die("new_ace", "Could not read first line");
        if (sscanf(dummy, "%11s %lf %lf %11s", ace.hz, &ace.aw, &ace.tz,
                   ace.hd) != 4)
                die("new_ace", "Could not parse first line");
        /* Read second line */
        if (fgets(ace.hk, 71, f) == NULL)
                die("new_ace", "Could not parse HK field");
        if (fgets(ace.hm, 11, f) == NULL)
                die("new_ace", "Could not parse HM field");
        /* Read IZ/AW array */
        for (int i = 0; i < 16; i++) {
                if (fscanf(f, "%d", &ace.iz[i]) != 1) {
                        die("new_ace", "Could not parse IZ[%d]", i);
                }
                if (fscanf(f, "%lf", &ace.awr[i]) != 1) {
                        die("new_ace", "Could not parse AW[%d]", i);
                }
        }
        /* Read nxs array */
        for (int i = 0; i < 16; i++)
                if (fscanf(f, "%d", &ace.nxs[i]) != 1)
                        die("new_ace", "Could not parse NXS[%d]", i);
        /* Read jxs array*/
        for (int i = 0; i < 32; i++)
                if (fscanf(f, "%d", &ace.jxs[i]) != 1)
                        die("new_ace", "Could not parse NXS[%d]", i);
        /* Read esz block */
        struct Esz *esz = &ace.esz;
        int loc         = ace.jxs[0];
        int ne          = ace.nxs[2];
        double dum;
        /* read to loc */
        for (int i = 0; i < loc - 1; i++)
                if (fscanf(f, "%lf", &dum) != 1)
                        die("new_ace", "Could not parse double");
        /*energy grid*/
        if ((esz->egrid = malloc(ne * sizeof esz->egrid)) == NULL)
                die("new_ace", "Allocation of egrid failed");
        for (int i = 0; i < ne; i++) {
                if (fscanf(f, "%lf", &(esz->egrid[i])) != 1)
                        die("new_ace", "Could not parse ESZ-energies");
        }
        /* total cross section */
        if ((esz->xstot = malloc(ne * sizeof esz->xstot)) == NULL)
                die("new_ace", "Allocation of xstot failed");
        for (int i = 0; i < ne; i++) {
                if (fscanf(f, "%lf", &(esz->xstot[i])) != 1)
                        die("new_ace", "Could not parse ESZ xstot section");
        }
        /* total neutron disappearance cross section */
        if ((esz->xsa = malloc(ne * sizeof esz->xsa)) == NULL)
                die("new_ace", "Allocation of xsa failed");
        for (int i = 0; i < ne; i++) {
                if (fscanf(f, "%lf", &(esz->xsa[i])) != 1)
                        die("new_ace", "Could not parse ESZ xsa section");
        }
        /* elastic cross section */
        if ((esz->xsel = malloc(ne * sizeof esz->xsa)) == NULL)
                die("new_ace", "Allocation of xsel failed");
        for (int i = 0; i < ne; i++) {
                if (fscanf(f, "%lf", &(esz->xsel[i])) != 1)
                        die("new_ace", "Could not parse ESZ xsel section");
        }
        /* average heating numbers */
        if ((esz->have = malloc(ne * sizeof esz->have)) == NULL)
                die("new_ace", "Allocation of have failed");
        for (int i = 0; i < ne; i++) {
                if (fscanf(f, "%lf", &(esz->have[i])) != 1)
                        die("new_ace", "Could not parse ESZ have section");
        }
        /* read mtr block */
        struct Mtr *mtr = &ace.mtr;
        int nmt         = ace.nxs[3];
        if ((mtr->mts = malloc(nmt * sizeof mtr->mts)) == NULL)
                die("new_ace", "Allocation of mts failed");
        for (int i = 0; i < nmt; i++)
                if (fscanf(f, "%d", &(mtr->mts[i])) != 1)
                        die("new_ace", "Could not parse MTR block");
        /* read lqr block */
        struct Lqr *lqr = &ace.lqr;
        if ((lqr->qs = malloc(nmt * sizeof mtr->mts)) == NULL)
                die("new_ace", "Allocation of qs failed");
        for (int i = 0; i < nmt; i++)
                if (fscanf(f, "%lf", &(lqr->qs[i])) != 1)
                        die("new_ace", "Could not parse LQR block");
        return ace;
}
