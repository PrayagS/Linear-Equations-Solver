#include <stdio.h>
#include <math.h>

int compareDoubles(double x, double y);
int swapRows(double **matrix, int current_row, int current_column, int rows, int cols);
void printMatrix(double **matrix, int rows, int cols);
void backSubstitution(double **matrix, int rows, int cols);
void fatMatrix(double **matrix, int rows, int cols);
void tallMatrix(double **matrix, int rows, int cols);
int countZeroRows(double** matrix, int rows, int cols);
void findNullSpace(double **matrix, int pivot_count, int zero_row_count, int rows, int cols);

void gaussianElimination(double **matrix, int rows, int cols){
    
    printf("\nThe Original Matrix\n\n");
    printMatrix(matrix, rows, cols);
    int a, b, c, d, e;
    int min = ((rows) > (cols-1)) ? cols-1 : rows-1; // Loop termination condition

    // Check for zero matrix
    int zero_row_count = countZeroRows(matrix, rows, cols);
    if(zero_row_count == rows){
        printf("The system is inconsistent and it has no solutions.\n\n");
        printf("Null Space = R_%d\n\n",rows);
        return;
    }

    // Gaussian Elimination happens here
    for(a=0, b=0, c=0; c < min; ++a, ++b, ++c){
        if(compareDoubles(matrix[a][b],0)){
            int flag = swapRows(matrix, a, b, rows, cols);
            if (flag == -1){
                --a;
                --c;
                continue;
            }
        }
        for (d = a+1; d < rows; d++){
            double factor = matrix[d][b]/matrix[a][b];
            for (e = 0; e < cols; e++){
                matrix[d][e] -= factor*matrix[a][e];        
            }
        }
    }

    // Count zero rows to count no. of pivots subsequently
    zero_row_count = countZeroRows(matrix, rows, cols);
    int pivot_count = rows - zero_row_count;

    // Unique solution => Null Space is zero dimensional
    if(pivot_count == cols-1){
        printf("As no. of pivots is equal to the no. of columns, nullity is zero. And hence, the nullspace of the matrix has only the zero vector.\n\n");    
    }

    // Inconsistent System => Null Space is R_n
    if(pivot_count == 0){
        printf("The system is inconsistent and it has no solutions.\n\n");
        printf("Null Space = R_%d\n\n",cols);
        return;
    }

    // Fat Matrix check
    if(cols-1 > rows){
        fatMatrix(matrix, rows, cols);
        findNullSpace(matrix, pivot_count, zero_row_count, rows, cols);
        return;
    }

    // Tall Matrix check
    if(rows > cols-1){
        tallMatrix(matrix, rows, cols);
        findNullSpace(matrix, pivot_count, zero_row_count, rows, cols);
        return;
    }

    // Start back substitution for square matrix
    backSubstitution(matrix, rows, cols);
    findNullSpace(matrix, pivot_count, zero_row_count, rows, cols);
}

int countZeroRows(double** matrix, int rows, int cols){
    int count = rows;
    int i, j;
    for(j = 0; j < rows; ++j){
        for(i = 0; i < cols-1; ++i){
            if(!compareDoubles(matrix[j][i],0)){
                --count;
                break;
            }
        }
    }
    return count;
}