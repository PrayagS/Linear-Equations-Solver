#include <stdio.h>

void swapTwoRows(double **matrix, int row1, int row2, int cols); 

void rowExchange(double **matrix, int **column_exchange_book, int size, int rows, int cols){
    int i;
    for(i = size-1; i >= 0; --i){
        swapTwoRows(matrix, column_exchange_book[i][0], column_exchange_book[i][1], cols);        
    }
}