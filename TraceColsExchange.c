#include <stdio.h>
#include <stdlib.h>

void swapCols(double** matrix, int column1, int column2, int rows);
void printMatrix(double** matrix, int rows, int cols);
void reverseGaussian(double **matrix, int pivot_count, int rows, int cols);
int compareDoubles(double x, double y);
void extractF(double **matrix, int pivot_count, int **column_exchange_book, int size, int rows, int cols);

void traceColsExchange(double **matrix, int pivot_count, int rows, int cols){
    int **column_exchange_book;
    column_exchange_book = (int **)calloc(cols-1, sizeof(int));
    int temp_index = 0;
    int i, j, k;
    for(i = 0; i < cols-1; ++i){
        column_exchange_book[i] = (int *)calloc(2, sizeof(int));
    }
    int min = ((rows) > (cols-1)) ? cols-1 : rows;
    for(i = 0, j = 0; j < min; ++i, ++j){
        if(compareDoubles(matrix[i][j],0)){
            for(k = j+1; k < cols-1; ++k){
                if(!compareDoubles(matrix[i][k],0)){
                    swapCols(matrix, j, k, rows);
                    column_exchange_book[temp_index][0] = j;
                    column_exchange_book[temp_index][1] = k;
                    ++temp_index;
                    break;
                }
            }
        }
    }
    // Reverse Gaussian elimination from the bottom-most pivot to create RREF of matrix
    reverseGaussian(matrix, pivot_count, rows, cols);

    // Extract matrix F from the RREF of matrix
    extractF(matrix, pivot_count, column_exchange_book, temp_index, rows, cols);
    free(column_exchange_book);
}
