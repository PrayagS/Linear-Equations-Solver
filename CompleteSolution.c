#include <stdio.h>

void printMatrix(double **matrix, int rows, int cols);
int compareDoubles(double x, double y);

void completeSolution(double **matrix, int pivot_count, int rows, int cols, double **matrixF, int rowsF, int **column_exchange_book, int size){
    int i, j = 0;
    int arr[cols-1];
    for(i = 0; i < cols-1; ++i){
        arr[i] = 0;
    }
    printf("Particular solution: \n");

    // As free variables are chosen as 0, particular value of non-free variables vector is equal to b from RREF of matrix 
    for(i = 0; i < pivot_count; ++i){
        if(i == column_exchange_book[j][0] && j < size){
            printf("x_p_%d = %.4lf\n",(column_exchange_book[j][1]+1),matrix[i][cols-1]);
            arr[column_exchange_book[j][1]] = -1;
            ++j;
        }
        else{
            printf("x_p_%d = %.4lf\n",(i+1),matrix[i][cols-1]);
            arr[i] = -1;
        }
    }

    // Assign free variables to 0
    for(i = 0; i < cols-1; ++i){
        if(arr[i] == 0){
            printf("x_p_%d = 0.0000\n",(i+1));
        }
    }

    // Take one column from null space matrix for the null solution
    printf("\nNull Solution: \n");
    printMatrix(matrixF, cols-1, cols-pivot_count-1);    
}