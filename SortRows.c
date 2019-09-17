#include <stdio.h>
#include <math.h>

void printMatrix(double **matrix, int rows, int cols);
void swapRows(double **matrix, int row1, int row2, int cols);
void insertionSort(double arr[], int n);
void reverseArray(double arr[], int start, int end);

void sortRows(double **matrix, int rows, int cols, int current_row, int current_column){
    double elements[rows-current_row];
    double temp[rows-current_row];
    for (size_t i = current_row; i < rows; i++){
        elements[i-current_row] = fabs(matrix[i][current_column]);
        temp[i-current_row] = elements[i-current_row];
    }
    insertionSort(elements, rows-current_row);
    reverseArray(elements, 0, rows-current_row-1);
    for (size_t i = current_row; i < rows; i++){
        for (size_t j = current_row; j < rows; j++){
            if (temp[i-current_row] == elements[j-current_row]){
                swapRows(matrix, i, j, cols);
                double temp_element = temp[i-current_row];
                temp[i-current_row] = temp[j-current_row];
                temp[j-current_row] = temp_element;
            }
        }
    }
}

void insertionSort(double arr[], int n) 
{ 
    int i, j;
    double key; 
    for (i = 1; i < n; i++){ 
        key = arr[i]; 
        j = i - 1; 
        while (j >= 0 && arr[j] > key){ 
            arr[j + 1] = arr[j]; 
            j = j - 1; 
        } 
        arr[j + 1] = key; 
    } 
}

void reverseArray(double arr[], int start, int end) 
{ 
    double temp; 
    while (start < end) 
    { 
        temp = arr[start];    
        arr[start] = arr[end]; 
        arr[end] = temp; 
        start++; 
        end--; 
    }    
}