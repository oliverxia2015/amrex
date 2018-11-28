#ifndef _AmrCoreAdv_F_H_
#define _AmrCoreAdv_F_H_

#include <AMReX_BLFort.H>
#include <AMReX_Box.H>
#include <AMReX_FArrayBox.H>
#include <AMReX_Geometry.H>

using namespace amrex;

    // these are C++ function definitions converted from Fortran 

    void initdata(const int level, const Real time,
                  Box const& bx, FArrayBox& phifab, 
                  GeometryData const & geom);

    void get_face_velocity(const int level, const Real time,
                           AMREX_D_DECL(FArrayBox& xvel,
                                        FArrayBox& yvel,
                                        FArrayBox& zvel),
                           GeometryData const& geom);

    void advect(const Real time, Box const& bx,
                const FArrayBox& statein,
                FArrayBox& stateout,
		AMREX_D_DECL(const FArrayBox& xvel,
                             const FArrayBox& yvel,
                             const FArrayBox& zvel),
                AMREX_D_DECL(FArrayBox& fx,
                             FArrayBox& fy,
                             FArrayBox& fz),
		const GpuArray<Real, AMREX_SPACEDIM>& dx, const Real dt);

    void compute_flux_3d(Box const& bx, GpuArray<Real, AMREX_SPACEDIM>& dtdx,
                         const FArrayBox& phifab,
                         AMREX_D_DECL(const FArrayBox& velx,
                                      const FArrayBox& vely,
                                      const FArrayBox& velz),
                         AMREX_D_DECL(FArrayBox& flxx,
                                      FArrayBox& flxy,
                                      FArrayBox& flxz));

    void slopex(Box const& bx,
                const FArrayBox &qfab,
                FArrayBox &dq4fab);

    void slopey(Box const& bx,
                const FArrayBox &qfab,
                FArrayBox &dq4fab);

    void slopez(Box const& bx,
                const FArrayBox &qfab,
                FArrayBox &dq4fab);

#ifdef __cplusplus
extern "C" 
{
#endif

    // these are interfaces to fortran subroutines

/*
    void initdata(const int* level, const amrex_real* time, 
		  const int* lo, const int* hi,
		  BL_FORT_FAB_ARG_3D(state),
		  const amrex_real* dx, const amrex_real* problo);


    void get_face_velocity(const int* level, const amrex_real* time, 
			   AMREX_D_DECL(BL_FORT_FAB_ARG(xvel),
				  BL_FORT_FAB_ARG(yvel),
				  BL_FORT_FAB_ARG(zvel)),
			   const amrex_real* dx, const amrex_real* problo);

    void advect(const amrex_real* time, const int* lo, const int* hi,
		const BL_FORT_FAB_ARG_3D(statein),
		BL_FORT_FAB_ARG_3D(stateout),
		AMREX_D_DECL(const BL_FORT_FAB_ARG_3D(xvel),
		       const BL_FORT_FAB_ARG_3D(yvel),
		       const BL_FORT_FAB_ARG_3D(zvel)),
		AMREX_D_DECL(BL_FORT_FAB_ARG_3D(fx),
		       BL_FORT_FAB_ARG_3D(fy),
		       BL_FORT_FAB_ARG_3D(fz)),
		const amrex_real* dx, const amrex_real* dt);
*/

    void state_error(int* tag, const int* tag_lo, const int* tag_hi,
		     const BL_FORT_FAB_ARG_3D(state),
		     const int* tagval, const int* clearval,
		     const int* lo, const int* hi,
		     const amrex_real* dx, const amrex_real* problo,
		     const amrex_real* time, const amrex_real* phierr);

    void phifill (BL_FORT_FAB_ARG_3D(state),
		  const int* dlo, const int* dhi,
		  const amrex_real* dx, const amrex_real* glo, 
		  const amrex_real* time, const int* bc);

#ifdef __cplusplus
}
#endif

#endif