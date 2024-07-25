/// MyCublas.cuh

#pragma once

#include "cuda_runtime.h"
#include "device_launch_parameters.h"
#include "cublas_v2.h"

extern "C" void MatrixMulVectorCublas(
        const double* matrix, const int row, const int col,
        const double* vector, double* result
);
