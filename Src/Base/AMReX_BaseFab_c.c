#include <AMReX_BaseFab_c.H>

#define DEFINE_STRIDES(q, qlo, qhi) \
    const int jstride_##q = qhi[0]-qlo[0]+1; \
    const int kstride_##q = jstride_##q*(qhi[1]-qlo[1]+1); \
    const int nstride_##q = kstride_##q*(qhi[2]-qlo[2]+1);

#define INDEX(q,i,j,k,n) \
    i-q##lo[0] + (j-q##lo[1])*jstride_##q + (k-q##lo[2])*kstride_##q + n*nstride_##q

#define INDEX_OFFSET(q,i,j,k,n,off) \
    i-q##lo[0]+off[0] + (j-q##lo[1]+off[1])*jstride_##q + (k-q##lo[2]+off[2])*kstride_##q + n*nstride_##q

#define GET_VALUE(q,i,j,k,n) q[INDEX(q,i,j,k,n)]
#define GET_VALUE_OFFSET(q,i,j,k,n,off) q[INDEX_OFFSET(q,i,j,k,n,off)]

amrex_real
amrex_c_fab_dot (const int* lo, const int* hi,
                 const amrex_real* restrict x, const int* xlo, const int* xhi,
                 const amrex_real* restrict y, const int* ylo, const int* yhi, const int* yblo,
                 const int* ncomp)
{
    amrex_real r = 0.0;

    DEFINE_STRIDES(x, xlo, xhi);
    DEFINE_STRIDES(y, ylo, yhi);

    for (int n = 0; n < *ncomp; ++n) {
        for (int k = lo[2]; k <= hi[2]; ++k) {
            for (int j = lo[1]; j <= hi[1]; ++j) {
                for (int i = lo[0]; i <= hi[0]; ++i) {
                    r = r + GET_VALUE(x,i,j,k,n) * GET_VALUE_OFFSET(y,i,j,k,n,yblo);
                }
            }
        }
    }

    return r;
}

