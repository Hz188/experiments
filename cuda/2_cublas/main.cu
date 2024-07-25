/// main.cpp

#include "MyCublas.cuh"

#include <iostream>

int main()
{
    /*
     *   matrix   = | 1.0, 2.0, 3.0, 4.0  |
     *              | 5.0, 6.0, 7.0, 8.0  |
     *              | 9.0, 10.0,11.0,12.0 |
     *
     *   vector   = | 1.0, 2.0, 3.0, 4.0  |
     *
     *   result   = | 30.0, 70.0, 11.0 |
     */

    const int row = 3;
    const int col = 4;

    double matrix[row * col] = {
            1.0, 5.0, 9.0,
            2.0, 6.0, 10.0,
            3.0, 7.0, 11.0,
            4.0, 8.0, 12.0
    };

    double vector[col] = { 1.0, 2.0, 3.0, 4.0 };

    double result[row] = { 0.0 };

    MatrixMulVectorCublas(matrix, row, col, vector, result);

    for (int i = 0; i < row; ++i)
    {
        printf("%.1f, ", result[i]);
    }
    return 0;
}
