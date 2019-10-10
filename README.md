  # Linear Equations Solver
  
  ## Description
  
  This implementation tries to solve given system Ax = b and outputs its unique solution if it exists. Else, it provides the null space of the matrix along with the complete solution. Feel free to open a pull request/issue in case the code doesn't work for a particular case.
  
  ## Instructions
  
  - Clone this repository  
  ```
  git clone https://github.com/PrayagS/Linear-Equations-Solver.git
  ```
  - Change into the directory  
  ```
  cd Linear-Equations-Solver
  ```
  - Execute the script to compile and execute the program  
  ```
  ./execute
  ```
  
  ## How it works
  
  - The main function obtains the input matrix.
  - Gaussian elimination performed on that matrix. Rows are swapped when pivots are not found. If no pivots are found, the program exits there itself with corresponding null space.
  - Then, back substitution is performed (separately for tall and square matrices) and infinite solutions/no solution is detected differently for fat matrices and tall matrices.
  - Now that solutions are calculated, null space calculation starts.
  - Before converting the matrix into RREF (row reduced echelon form), zero rows are moved to the bottom and columns are exchanged such that the matrix can be divided into two submatrices, one being the identity matrix and the other called F such that the original matrix can be represented as [ I F ] (zero rows ignored here).
  - Then, Gaussian elimination is performed again to convert the upper triangular matrix to RREF.
  - After that, matrix F is extracted from the main matrix and null space matrix i.e. the matrix with -F as one submatrix and an identity matrix with the same no. of columns as F appended below it, is formed.
  - Once the null space is calculated, the particular solution is calculated and subsequently, the complete solution is calculated.
