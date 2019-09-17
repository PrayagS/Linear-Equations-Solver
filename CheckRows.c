#include <stdio.h>

int compareDoubles(double x, double y);

int checkRows(double** matrix, int rows, int cols){
    int row_count = 0;
    int i, j;
    for(i = 0; i < rows; i++){
        int counter = 0;
        for(j = 0; j < cols-1; j++){
            if(compareDoubles(matrix[i][j],0)){
                ++counter;
            }
        }
        if(counter == cols-1){
            if(!compareDoubles(matrix[i][cols-1],0)){
                ++row_count; 
                return -1;
            }    
            else row_count++;
        }
    }
    if(row_count > 0) return row_count;
    else return 0;
}