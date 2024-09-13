#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Declare the matrix functions
double **Matsec(double **a, double **b, int m, double k);
double **Matadd(double **a, double **b, int m, int n);
double **Matscale(double **a, int m, int n, double k);
double **createMat(int m, int n);
void printMat(double **p, int m, int n);

int main() {
    // Open a file to store the output
    FILE *fp = fopen("output.dat", "w");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    // Coordinates of points A(6, -4) and B(-2, -7)
    double **A = createMat(2, 1);
    double **B = createMat(2, 1);
    
    A[0][0] = 6;  // x1
    A[1][0] = -4; // y1
    B[0][0] = -2; // x2
    B[1][0] = -7; // y2

    // Since the Y-axis divides the line, x = 0. We use the section formula for the x-coordinate:
    // 0 = (k * x2 + x1) / (k + 1)
    // Solve for k: 0 = (k * -2 + 6) / (k + 1)
    // k = 3

    double k = 3;

    // Now, find the point of intersection using the section formula
    double **P = Matsec(A, B, 2, k);

    // Print results to console
    printf("The ratio in which the Y-axis divides the line is: %.2f:1\n", k);
    printf("The point of intersection is: (%.2f, %.2f)\n", P[0][0], P[1][0]);

    // Write results to the file
    fprintf(fp, "The ratio in which the Y-axis divides the line is: %.2f:1\n", k);
    fprintf(fp, "The point of intersection is: (%.2f, %.2f)\n", P[0][0], P[1][0]);

    // Close the file
    fclose(fp);

    // Free allocated memory
    free(A);
    free(B);
    free(P);

    return 0;
}

// Function to create an m x n matrix
double **createMat(int m, int n) {
    int i;
    double **a = (double **)malloc(m * sizeof(double *));
    for (i = 0; i < m; i++) {
        a[i] = (double *)malloc(n * sizeof(double));
    }
    return a;
}

// Section formula
double **Matsec(double **a, double **b, int m, double k) {
    double **temp = createMat(m, 1);
    temp = Matscale(Matadd(a, Matscale(b, m, 1, k), m, 1), m, 1, 1 / (k + 1));
    return temp;
}

// Add two matrices
double **Matadd(double **a, double **b, int m, int n) {
    int i, j;
    double **c = createMat(m, n);
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            c[i][j] = a[i][j] + b[i][j];
        }
    }
    return c;
}

// Scale a matrix
double **Matscale(double **a, int m, int n, double k) {
    int i, j;
    double **c = createMat(m, n);
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            c[i][j] = k * a[i][j];
        }
    }
    return c;
}

// Print matrix
void printMat(double **p, int m, int n) {
    int i, j;
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            printf("%lf ", p[i][j]);
        }
        printf("\n");
    }
}

