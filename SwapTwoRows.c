#include <stdio.h>

void swapTwoRows(double **matrix, int row1, int row2, int cols){
    int j;
    for(j = 0; j < cols; ++j){
        double temp = matrix[row1][j];
        matrix[row1][j] = matrix[row2][j];
        matrix[row2][j] = temp;
    }
}