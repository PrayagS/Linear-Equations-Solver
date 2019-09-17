#include <stdio.h>

int compareDoubles(double x, double y);

int swapRows(double **matrix, int current_row, int current_column, int rows, int cols){
    int i, j, k;
    int swap_with = -1;

    for (i = current_row+1; i < rows; i++){
        if(!compareDoubles(matrix[i][current_column],0)){
            swap_with = i;
        }
    }

    if(swap_with == -1){
        return -1;
    }

    double temp[cols];
    for (j = 0; j < cols; i++){
        temp[j] = matrix[current_row][j];
    }
    for (k = 0; k < cols; i++){
        matrix[current_row][k] = matrix[swap_with][k];
        matrix[swap_with][k] = temp[k];
    }
    return 0;
}