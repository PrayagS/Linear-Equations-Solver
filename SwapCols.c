#include <stdio.h>

void swapCols(double** matrix, int column1, int column2, int rows){
    int j;
    for(j = 0; j < rows; ++j){
        double temp = matrix[j][column1];
        matrix[j][column1] = matrix[j][column2];
        matrix[j][column2] = temp;
    }    
}