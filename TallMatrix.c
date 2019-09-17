#include <stdio.h>
#include <math.h>

int checkRows(double **matrix, int rows, int cols);

void tallMatrix(double **matrix, int rows, int cols){
    double x[cols-1];

    // Check for inconsistent system
    int zeroRows = checkRows(matrix, rows, cols);
    if(zeroRows == -1){
        printf("The system is inconsistent. It has no solutions\n");
        return;
    }

    // Check for infinite solutions
    if(rows-zeroRows < cols-1){
        printf("The system is consistent. It has infinitely many solutions\n");
        return;
    }

    // Back substitution in case of unique solutions.
    int xtemp = cols - 1;
    int i, j;
    for(i = rows-zeroRows; i >= 0; i--){
        x[i] = matrix[i][xtemp];
        for(j = i+1; j < xtemp; ++j){
            x[i] = x[i] - matrix[i][j]*x[j];
        }
        x[i] = x[i] / matrix[i][i];
    }
    for (i = 0; i < xtemp; i++){
        printf("x_%d = %.4lf\n",(i+1),x[i]);
    }
}