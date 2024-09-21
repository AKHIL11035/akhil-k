import numpy as np
import numpy.linalg as LA

#Direction vector between points A and B
def dir_vec(A,B):
    return B-A

#Generate points on the line between A and B
def line_gen(A,B):
    len = 10
    dim = A.shape[0]
    x_AB = np.zeros((dim, len))
    lam_1 = np.linspace(0, 1, len)
    for i in range(len):
        temp1 = A + lam_1[i]*(B-A)
        x_AB[:, i] = temp1.T
    return x_AB

# Compute the dot product of vectors
def dot_product(a, b):
    return np.dot(a, b)

# Find the value of lambda where scalar product = 1
def find_lambda():
    a = np.array([1, 1, 1])      # Vector a
    b = np.array([2, 4, -5])     # Vector b

    for lambda_val in np.arange(-10, 10, 0.001):  # Iterate over possible lambda values
        c = np.array([lambda_val, 2, 3])         # Vector c with lambda
        bc_sum = b + c                           # b + c vector sum
        unit_bc = bc_sum / LA.norm(bc_sum)       # Unit vector of b + c

        if np.isclose(dot_product(a, unit_bc), 1):  # Check if scalar product equals 1
            return lambda_val, unit_bc

# Main execution
lambda_val, unit_bc = find_lambda()
print(f"Value of lambda: {lambda_val}")
print(f"Unit vector along b + c: {unit_bc}")

