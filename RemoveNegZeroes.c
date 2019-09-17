#include <stdio.h>
#include <math.h>

int compareDoubles(double x, double y);

void removeNegZeroes(double **matrix, int rows, int cols){
    int i, j;
    for(i = 0; i < rows; ++i){
        for(j = 0; j < cols; ++j){
            if(compareDoubles(matrix[i][j], 0)){
                matrix[i][j] = 0;
            }
        }
    }
}