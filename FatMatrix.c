#include <stdio.h>
#include <math.h>

int checkRow(double **matrix, int current_row, int cols);
int compareDoubles(double x, double y);

void fatMatrix(double **matrix, int rows, int cols){
    int i;

    // As fat matrix will never have unique solutions, check for infinite or no solution.
    for(i = rows-1; i >= 0; i--){
        int flag = checkRow(matrix, i, cols);
        if(flag == -1){
            printf("The system is inconsistent. It has no solutions.\n");
            return;
        }
        else{
            printf("The system has infinitely many solutions.\n");
            return;
        }
    }
}

int checkRow(double **matrix, int current_row, int cols){
    int allXZeroes = 1;
    int bZero = 1;
    int i;
    for(i = 0; i < cols-1; ++i){
        if(!compareDoubles(matrix[current_row][i],0)){
            allXZeroes = 0;
            break;
        }
    }
    if(matrix[current_row][cols-1] != 0){
        bZero = 0;
    }
    if(allXZeroes == 1 && bZero == 0){
        return -1;
    }
    return 1;
}