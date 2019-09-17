#include <stdio.h>

void printMatrix(double **matrix, int rows, int cols){
    int i, j;
    for (i = 0; i < rows; i++){
        for (j = 0; j < cols; j++){
            printf("%.4lf ",matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}