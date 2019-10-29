#include <stdio.h>
#include <stdlib.h>

void printMatrix(double **matrix, int rows, int cols);
int compareDoubles(double x, double y);
double** generateI(int dimension);
void rowExchange(double **matrixF, int **column_exchange_book, int size, int rows, int cols);
void completeSolution(double **matrix, int pivot_count, int rows, int cols, double **matrixF, int rowsF, int **column_exchange_book, int size);
void swapCols(double** matrix, int column1, int column2, int rows);

void extractF(double **matrix, int pivot_count, int **column_exchange_book, int size, int rows, int cols){
    double **matrixF;
    if(cols-1-pivot_count == 0){
        return;
    }
    matrixF = (double **)calloc(cols-1, sizeof(double));
    int i, j;
    for(i = 0; i < cols-1; ++i){
        matrixF[i] = (double *)calloc(cols-1-pivot_count, sizeof(double));
    }
    for(i = 0; i < pivot_count; ++i){
        for(j = pivot_count; j < cols; ++j){
            if(compareDoubles(matrix[i][j],0)){
                matrixF[i][j-pivot_count] = matrix[i][j];    
            }
            else{
                matrixF[i][j-pivot_count] = -1*matrix[i][j];
            }
        }
    }

    // Generate Identity matrix of appropriate dimension
    double** I = generateI(cols-pivot_count-1);
    for(i = pivot_count; i < cols-1; ++i){
        for(j = pivot_count; j < cols; ++j){
            matrixF[i][j-pivot_count] = I[i-pivot_count][j-pivot_count];
        }    
    }

    // Exchange rows according to which columns were swapped in the original matrix
    rowExchange(matrixF, column_exchange_book, size, cols-1, cols-pivot_count-1);
    printf("\nNull Space: \n\n");
    printMatrix(matrixF, cols-1, cols-pivot_count-1);

    // Find complete solution of the system
    printf("Complete Solution:\n\n");
    completeSolution(matrix, pivot_count, rows, cols, matrixF, cols-1, column_exchange_book, size);
    printf("\nThus, the complete solution of the system is x_p + k*x_n, where k is the coefficient matrix of corresponding size.");
    free(matrixF);
    free(I);
}

double** generateI(int dimension){
    double** I_nxn;
    I_nxn = (double**)calloc(dimension, sizeof(double));
    int i, j;
    for(i = 0; i < dimension; ++i){
        I_nxn[i] = (double*)calloc(dimension, sizeof(double));
    }
    for(i = 0; i < dimension; ++i){
        for(j = 0; j < dimension; ++j){
            if(i == j){
                I_nxn[i][j] = 1;
            }
            else{
                I_nxn[i][j] = 0;
            }
        }
    }
    return I_nxn;
}