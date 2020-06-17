#!/bin/bash

# Example CMake config script for an OSX laptop with OpenMPI

cmake -DCMAKE_INSTALL_PREFIX:PATH=./install \
      -DCMAKE_CXX_COMPILER:STRING=mpicxx \
      -DCMAKE_C_COMPILER:STRING=mpicc \
      -DCMAKE_Fortran_COMPILER:STRING=mpifort \
      -DMPIEXEC_PREFLAGS:STRING=--oversubscribe \
      -DCMAKE_BUILD_TYPE:STRING=Release \
      -DPELEC_DIM:STRING=3 \
      -DPELEC_ENABLE_MPI:BOOL=ON \
      -DPELEC_ENABLE_TESTS:BOOL=ON \
      -DPELEC_ENABLE_MASA:BOOL=ON \
      -DPELEC_ENABLE_FCOMPARE:BOOL=ON \
      -DPELEC_ENABLE_FCOMPARE_FOR_TESTS:BOOL=OFF \
      -DMASA_DIR:STRING=$(spack location -i masa) \
      -DPELEC_ENABLE_DOCUMENTATION:BOOL=OFF \
      -DCMAKE_EXPORT_COMPILE_COMMANDS:BOOL=ON \
      .. && make -j8
