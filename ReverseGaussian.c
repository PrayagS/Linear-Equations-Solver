#include <stdio.h>

int compareDoubles(double x, double y);
void printMatrix(double **matrix, int rows, int cols);

void reverseGaussian(double **matrix, int pivot_count, int rows, int cols){
    int i, j, k, l, m;
    for(i=pivot_count-1, j=pivot_count-1; i>=0 && j>=0; --i, --j){
        double temp = matrix[i][j];
        for(m = 0; m < cols; ++m){
            if(matrix[i][j] < (double)0 && compareDoubles(matrix[i][m],0)){
                continue;
            }
            matrix[i][m] /= temp;
        }
        for (k = i-1; k >= 0; --k){
            double factor = matrix[k][j]/matrix[i][j];
            for (l = 0; l < cols; l++){
                matrix[k][l] -= factor*matrix[i][l];        
            }
        }
    }
}