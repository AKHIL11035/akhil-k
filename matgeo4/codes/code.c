#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to create a matrix
double **createMat(int m, int n) {
    int i;
    double **a;
    a = (double **)malloc(m * sizeof(*a));
    for (i = 0; i < m; i++)
        a[i] = (double *)malloc(n * sizeof(*a[i]));
    return a;
}

// Function to calculate the area between the parabola and the line
double calculateArea(double a, double b, int n) {
    double deltaX = (b - a) / n; // Width of each trapezoid
    double area = 0.0;

    for (int i = 0; i < n; i++) {
        double x1 = a + i * deltaX;
        double x2 = a + (i + 1) * deltaX;

        // Calculate the height of the parabola at x1 and x2
        double y1 = 2 * sqrt(x1); // From y^2 = 4x -> y = 2*sqrt(x)
        double y2 = 2 * sqrt(x2);

        // Area of trapezoid = (base1 + base2) * height / 2
        area += (y1 + y2) * deltaX / 2;
    }

    return area;
}

int main() {
    // Define the limits of integration and number of trapezoids
    double lowerLimit = 0.0; // Lower limit of x (where parabola starts)
    double upperLimit = 3.0; // Upper limit of x (line x=3)
    int n = 1000; // Number of trapezoids for integration

    // Calculate the area
    double area = calculateArea(lowerLimit, upperLimit, n);
    
    // Since we need the area above and below the x-axis:
    area *= 2; // Multiply by 2 to account for symmetry
    
    // Output the result to output.dat
    FILE *file = fopen("output.dat", "w");
    if (file == NULL) {
        fprintf(stderr, "Error opening file!\n");
        return 1;
    }

    fprintf(file, "Area enclosed between the parabola and the line: %lf\n", area);
    fclose(file);

    printf("Area has been calculated and saved to output.dat\n");

    return 0;
}


