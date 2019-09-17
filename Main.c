#include <stdio.h>
#include <stdlib.h>

void inputMatrix(double **matrix);

int main(){
    double **augmentedMatrix = 0;
    inputMatrix(augmentedMatrix);
    free(augmentedMatrix);
    return 0;
}