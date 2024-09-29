import numpy as np
import matplotlib.pyplot as plt

# Define the vectors a, b, and c (with lambda = 1)
a = np.array([1, 1, 1])
b = np.array([2, 4, -5])
c = np.array([1, 2, 3])  # lambda = 1

# Vector b + c
b_plus_c = b + c

# Unit vector along b + c
magnitude_b_plus_c = np.linalg.norm(b_plus_c)
unit_vector_b_plus_c = b_plus_c / magnitude_b_plus_c

# Plot the vectors
fig = plt.figure()
ax = fig.add_subplot(111, projection='3d')

# Plot vector a (red)
ax.quiver(0, 0, 0, a[0], a[1], a[2], color='r', label='a')

# Plot vector b (green)
ax.quiver(0, 0, 0, b[0], b[1], b[2], color='g', label='b')

# Plot vector c (cyan)
ax.quiver(0, 0, 0, c[0], c[1], c[2], color='c', label='c')

# Plot vector b + c (blue)
ax.quiver(0, 0, 0, b_plus_c[0], b_plus_c[1], b_plus_c[2], color='b', label='b+c')

# Plot the unit vector along b + c (black)
ax.quiver(0, 0, 0, unit_vector_b_plus_c[0], unit_vector_b_plus_c[1], unit_vector_b_plus_c[2], color='k', label='unit(b+c)')

# Set labels
ax.set_xlabel('X')
ax.set_ylabel('Y')
ax.set_zlabel('Z')

# Show legend
ax.legend()

# Show plot
plt.show()

