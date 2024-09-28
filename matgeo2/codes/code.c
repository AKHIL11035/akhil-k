#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function declarations
double **createMat(int m, int n);
void printMatToFile(double **p, int m, int n, FILE *fp);
double Matdot(double **a, double **b, int m);
double Matnorm(double **a, int m);
double **Matadd(double **a, double **b, int m, int n);
double **Matscale(double **a, int m, int n, double k);

// Main function
int main() {
    double lambda;
    double **a, **b, **c, **sum, **unitVec;
    double scalarProduct;

    // Open a file to write the results
    FILE *outputFile = fopen("output.dat", "w");
    if (outputFile == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    // Initialize vector a = [1, 1, 1]
    a = createMat(3, 1);
    a[0][0] = 1;
    a[1][0] = 1;
    a[2][0] = 1;

    // Initialize vector b = [2, 4, -5]
    b = createMat(3, 1);
    b[0][0] = 2;
    b[1][0] = 4;
    b[2][0] = -5;

    // Initialize vector c = [lambda, 2, 3]
    c = createMat(3, 1);

    // Loop to find the correct lambda
    for (lambda = -100; lambda <= 100; lambda += 0.01) {
        c[0][0] = lambda;
        c[1][0] = 2;
        c[2][0] = 3;

        // Sum vectors b + c
        sum = Matadd(b, c, 3, 1);

        // Normalize the sum to get unit vector
        unitVec = Matscale(sum, 3, 1, 1 / Matnorm(sum, 3));

        // Compute scalar product of a with unit vector along b + c
        scalarProduct = Matdot(a, unitVec, 3);

        // Check if the scalar product is equal to 1
        if (fabs(scalarProduct - 1.0) < 1e-6) {
            // Write the results to the output file
            fprintf(outputFile, "Found lambda = %lf\n", lambda);
            fprintf(outputFile, "Unit vector along b + c:\n");
            printMatToFile(unitVec, 3, 1, outputFile);
            break;
        }
    }

    // Free dynamically allocated memory
    free(a);
    free(b);
    free(c);
    free(sum);
    free(unitVec);

    // Close the output file
    fclose(outputFile);

    return 0;
}

// Function implementations

// Function to create a matrix
double **createMat(int m, int n) {
    double **a = (double **)malloc(m * sizeof(double *));
    for (int i = 0; i < m; i++) {
        a[i] = (double *)malloc(n * sizeof(double));
    }
    return a;
}

// Function to print matrix to file
void printMatToFile(double **p, int m, int n, FILE *fp) {
    int i, j;
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            fprintf(fp, "%lf ", p[i][j]);
        }
        fprintf(fp, "\n");
    }
}

// Function to compute the inner product of two vectors
double Matdot(double **a, double **b, int m) {
    double dotProduct = 0;
    for (int i = 0; i < m; i++) {
        dotProduct += a[i][0] * b[i][0];
    }
    return dotProduct;
}

// Function to compute the norm (magnitude) of a vector
double Matnorm(double **a, int m) {
    return sqrt(Matdot(a, a, m));
}

// Function to add two matrices
double **Matadd(double **a, double **b, int m, int n) {
    double **c = createMat(m, n);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            c[i][j] = a[i][j] + b[i][j];
        }
    }
    return c;
}

// Function to scale a matrix by a scalar
double **Matscale(double **a, int m, int n, double k) {
    double **c = createMat(m, n);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            c[i][j] = a[i][j] * k;
        }
    }
    return c;
}

