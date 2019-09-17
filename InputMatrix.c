#include <stdio.h>
#include <stdlib.h>

void gaussianElimination(double **matrix, int rows, int cols);

void inputMatrix(double **matrix){
    printf("\nMatrix Solution Finder\n\n");
    int rows, cols;
    printf("Enter the no. of rows and columns in the augmented matrix:");
    scanf("%d %d",&rows,&cols);

    // Allocate memory to the matrix pointer
    matrix = (double **)calloc(rows, sizeof(double));
    int i, j;
    for (i = 0; i < rows; i++){
        matrix[i] = (double *)calloc(cols, sizeof(double));
    }
    printf("Enter the elements:\n");
    for (i = 0; i < rows; i++){
        for (j = 0; j < cols; j++){
            scanf("%lf",&matrix[i][j]);
        }
    }
    gaussianElimination(matrix, rows, cols);
}
