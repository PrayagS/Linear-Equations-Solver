#include <stdio.h>

int compareDoubles(double x, double y);
int checkZeroRow(double **matrix, int current_row, int cols);
void swapTwoRows(double **matrix, int row1, int row2, int cols);

void swapZeroRows(double **matrix, int zero_row_count, int rows, int cols){
    int counter = 0;
    int i, j;
    for(i = rows-1; i >= rows-zero_row_count; --i){
        if(checkZeroRow(matrix, i, cols) == 1){
            ++counter;
        }
    }
    if(counter == zero_row_count){
        return;
    }
    int swap_with = rows-1;
    for(i = 0; i < zero_row_count; ++i){
        for(j = 0; j < rows; ++j){
            if(checkZeroRow(matrix, j, cols) == 1){
                if(checkZeroRow(matrix, swap_with, cols) == 0){
                    swapTwoRows(matrix, j, swap_with, cols);
                    break;
                }
                else{
                    --swap_with;
                    --j;
                    continue;
                }
            }
        }
    }
}

int checkZeroRow(double **matrix, int current_row, int cols){
    int i;
    for(i = 0; i < cols-1; ++i){
        if(!compareDoubles(matrix[current_row][i],0)){
            return 0;
        }
    }
    return 1;
}