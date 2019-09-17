#include <stdio.h>

void traceColsExchange(double **matrix, int pivot_count, int rows, int cols);
void swapZeroRows(double **matrix, int zero_row_count, int rows, int cols);

void findNullSpace(double **matrix, int pivot_count, int zero_row_count, int rows, int cols){
    // Shift zero rows to the bottom of the matrix
    swapZeroRows(matrix, zero_row_count, rows, cols);

    // Swap columns while finding null space and keep trace of that.
    traceColsExchange(matrix, pivot_count, rows, cols);  
}