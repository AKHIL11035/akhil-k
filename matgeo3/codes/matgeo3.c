#include <stdio.h>
#include <math.h>

// Function to calculate f(x) = (x + 2) - x^2
double f(double x) {
    return (x + 2) - (x * x);
}

// Numerical integration using the trapezoidal rule
double integrate(double (*func)(double), double a, double b, int n) {
    double h = (b - a) / n;
    double sum = 0.5 * (func(a) + func(b));
    
    for (int i = 1; i < n; i++) {
        sum += func(a + i * h);
    }
    
    return sum * h;
}

int main() {
    // Define the limits of integration
    double a = -1.0;
    double b = 2.0;
    int n = 10000; // Number of intervals (increase for better accuracy)

    // Calculate the area using numerical integration
    double area = integrate(f, a, b, n);
    
    // Print the result
    printf("The area enclosed by the parabola and the line is: %lf\n", area);

    // Write the result to a file
    FILE *file = fopen("area_output.dat", "w");
    if (file == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    fprintf(file, "The area enclosed by the parabola and the line is: %lf\n", area);
    fclose(file);

    return 0;
}

