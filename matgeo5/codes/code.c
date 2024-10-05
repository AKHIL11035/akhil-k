//Functions created by
// G V V Sharma
// October 27, 2023
// Revised November 13, 2023
 #include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function declarations
double **createMat(int rows, int cols);
double **Matinv(double **A, int n);
double **Matmul(double **A, double **B, int rowsA, int colsA, int colsB);
void writeMatToFile(FILE *file, double **mat, int rows, int cols);
double calculateArea(double X1[], double X2[], double X3[]);

// Function to create a matrix
double **createMat(int rows, int cols) {
    double **mat = (double **)malloc(rows * sizeof(double *));
    for (int i = 0; i < rows; i++) {
        mat[i] = (double *)malloc(cols * sizeof(double));
    }
    return mat;
}

// Function to calculate the inverse of a 2x2 matrix
double **Matinv(double **A, int n) {
    double det = A[0][0] * A[1][1] - A[0][1] * A[1][0];
    if (det == 0) {
        printf("Matrix is singular, can't find its inverse.\n");
        exit(1);
    }
    
    double **inv = createMat(2, 2);
    inv[0][0] = A[1][1] / det;
    inv[0][1] = -A[0][1] / det;
    inv[1][0] = -A[1][0] / det;
    inv[1][1] = A[0][0] / det;
    
    return inv;
}

// Function to multiply two matrices
double **Matmul(double **A, double **B, int rowsA, int colsA, int colsB) {
    double **result = createMat(rowsA, colsB);
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsB; j++) {
            result[i][j] = 0;
            for (int k = 0; k < colsA; k++) {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return result;
}

// Function to write a matrix to a file
void writeMatToFile(FILE *file, double **mat, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            fprintf(file, "%lf ", mat[i][j]);
        }
        fprintf(file, "\n");
    }
}

// Function to calculate the area of a triangle given 3 points
double calculateArea(double X1[], double X2[], double X3[]) {
    double area = 0.5 * fabs(X1[0]*(X2[1] - X3[1]) + X2[0]*(X3[1] - X1[1]) + X3[0]*(X1[1] - X2[1]));
    return area;
}

int main() {
    // Define the coefficient matrices (A1, A2, A3) and constant matrices (B1, B2, B3)
    double A1[2][2] = {{3, -2}, {2, 3}};
    double B1[2][1] = {{-1}, {21}};
    
    double A2[2][2] = {{2, 3}, {1, -5}};
    double B2[2][1] = {{21}, {-9}};
    
    double A3[2][2] = {{3, -2}, {1, -5}};
    double B3[2][1] = {{-1}, {-9}};
    
    // Open the output file
    FILE *file = fopen("output.dat", "w");
    if (file == NULL) {
        printf("Error opening file for writing.\n");
        return 1;
    }

    double **A, **B, **A_inv, **X1, **X2, **X3;

    // Solve for the first pair of lines
    A = createMat(2, 2);
    A[0][0] = 3; A[0][1] = -2;
    A[1][0] = 2; A[1][1] = 3;
    
    B = createMat(2, 1);
    B[0][0] = -1;
    B[1][0] = 21;
    
    A_inv = Matinv(A, 2);
    X1 = Matmul(A_inv, B, 2, 2, 1);

    fprintf(file, "Intersection point 1:\n");
    writeMatToFile(file, X1, 2, 1);
    
    // Solve for the second pair of lines
    A[0][0] = 2; A[0][1] = 3;
    A[1][0] = 1; A[1][1] = -5;
    
    B[0][0] = 21;
    B[1][0] = -9;
    
    A_inv = Matinv(A, 2);
    X2 = Matmul(A_inv, B, 2, 2, 1);

    fprintf(file, "Intersection point 2:\n");
    writeMatToFile(file, X2, 2, 1);
    
    // Solve for the third pair of lines
    A[0][0] = 3; A[0][1] = -2;
    A[1][0] = 1; A[1][1] = -5;
    
    B[0][0] = -1;
    B[1][0] = -9;
    
    A_inv = Matinv(A, 2);
    X3 = Matmul(A_inv, B, 2, 2, 1);

    fprintf(file, "Intersection point 3:\n");
    writeMatToFile(file, X3, 2, 1);
    
    // Convert matrices to arrays for area calculation
    double X1_array[2] = {X1[0][0], X1[1][0]};
    double X2_array[2] = {X2[0][0], X2[1][0]};
    double X3_array[2] = {X3[0][0], X3[1][0]};
    
    // Calculate the area of the triangle formed by the three intersection points
    double area = calculateArea(X1_array, X2_array, X3_array);
    fprintf(file, "\nArea of the triangle: %lf\n", area);

    // Close the file
    fclose(file);
    
    // Free allocated memory
    free(A);
    free(B);
    free(A_inv);
    free(X1);
    free(X2);
    free(X3);
    
    return 0;
}


