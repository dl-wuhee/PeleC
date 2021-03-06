#include <AMReX_LevelBld.H>

#include "PeleC.H"

class PeleCBld : public amrex::LevelBld
{
  virtual void variableSetUp();
  virtual void variableCleanUp();
  virtual amrex::AmrLevel* operator()();
  virtual amrex::AmrLevel* operator()(
    amrex::Amr& papa,
    int lev,
    const amrex::Geometry& level_geom,
    const amrex::BoxArray& ba,
    const amrex::DistributionMapping& dm,
    amrex::Real time);
};

PeleCBld PeleC_bld;

amrex::LevelBld*
getLevelBld()
{
  return &PeleC_bld;
}

void
PeleCBld::variableSetUp()
{
  PeleC::variableSetUp();
}

void
PeleCBld::variableCleanUp()
{
  PeleC::variableCleanUp();
}

amrex::AmrLevel*
PeleCBld::operator()()
{
  return new PeleC;
}

amrex::AmrLevel*
PeleCBld::operator()(
  amrex::Amr& papa,
  int lev,
  const amrex::Geometry& level_geom,
  const amrex::BoxArray& ba,
  const amrex::DistributionMapping& dm,
  amrex::Real time)
{
  return new PeleC(papa, lev, level_geom, ba, dm, time);
}
