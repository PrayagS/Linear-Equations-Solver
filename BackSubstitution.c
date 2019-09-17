#include <stdio.h>
#include <math.h>

void printMatrix(double **matrix, int rows, int cols);
int compareDoubles(double x, double y);
int checkRows(double** matrix, int rows, int cols);
int allOtherZeroes(double **matrix, int current_row, int that_column, int cols);
int search(int* arr, int n, int x);

void backSubstitution(double **matrix, int rows, int cols){
    double x[cols-1];
    int zero_rows[cols-1];
    int zero_row_count = 0;
    int i;
    for (i = 0; i < cols-1; i++){
        x[i] = 0;
    }

    // Check for no solutions.
    if(checkRows(matrix, rows, cols) == -1){
        printf("The system is inconsistent. It has no solutions.\n");
        return;
    }

    // Check for free variable in the last row
    if((matrix[rows-1][cols-2]/matrix[rows-1][cols-1]) == (double)0){
        printf("The system is inconsistent. It has no solutions.\n");
        return;
    }
    else{
        if(matrix[rows-1][cols-2] == (double)0){
                zero_rows[zero_row_count] = cols-2;
                ++zero_row_count;
        }
        else{
            x[cols-2] = matrix[rows-1][cols-1]/matrix[rows-1][cols-2];
        }
    }

    // Back Substitution starts here
    int j;
	for (i = rows-2; i >= 0; i--) {
		for (j = cols-2; j >= (i+1); j--) {
            // Check for free variables
            if(search(zero_rows, zero_row_count, j) == 1){
                // If free variable is found and it's coefficient is non-zero => infinite solutions
                if(!compareDoubles(matrix[i][j],0) && allOtherZeroes(matrix, i, j, cols) == -1){
                    printf("The system has infinitely many solutions.\n");
                    return;
                }
                else{
                    ++j;
                    continue;
                }
            }
			matrix[i][cols-1] = matrix[i][cols-1] - matrix[i][j]*x[j];
            if(compareDoubles(matrix[i][cols-1],0)){
                zero_rows[zero_row_count] = i;
                ++zero_row_count;
                continue;
            }
			x[i] = matrix[i][cols-1]/matrix[i][i];
		}
	}

    // Print unique solutions to the system
    printf("Unique Solution: \n\n");
    for (i = cols-2; i >= 0; i--){
        printf("x_%d = %.4lf\n",(i+1),x[i]);
    }
}

int allOtherZeroes(double **matrix, int current_row, int that_column, int cols){
    int i;
    for (i = 0; i < cols-1; i++){
        if(i == that_column){
            continue;
        }
        else{
            if(!compareDoubles(matrix[current_row][i],0)){
                return -1;
            }
        }       
    }
    return 1;
}

int search(int* arr, int n, int x) 
{ 
    int i;
    for (i = 0; i < n+1; i++) 
        if (arr[i] == x){
            return 1;
        } 
    return -1;
}