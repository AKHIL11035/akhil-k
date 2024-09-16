import numpy as np
import matplotlib.pyplot as plt

# Given points A(6, -4) and B(-2, -7)
A = np.array([6, -4])
B = np.array([-2, -7])

m = 3
n = 1
intersection_y = (m * B[1] + n * A[1]) / (m + n)

# Point of intersection with the Y-axis
intersection_point = np.array([0, intersection_y])

# Output the ratio and intersection point
print("The ratio in which the Y-axis divides the line segment is 3:1.")
print(f"The point of intersection on the Y-axis is: {intersection_point}")

# Plotting the points and the line segment

# Line generation function
def line_gen(A, B):
    line = np.zeros((2, 10))
    lam_1 = np.linspace(0, 1, 10)
    for i in range(10):
        temp = A + lam_1[i] * (B - A)
        line[:, i] = temp
    return line

# Generate line segment AB
x_AB = line_gen(A, B)

# Plot line AB
plt.plot(x_AB[0, :], x_AB[1, :], label='$AB$')

# Plot the points A, B, and the intersection point
points = np.block([[A], [B], [intersection_point]])
plt.scatter(points[:, 0], points[:, 1], color='red')

# Label the points
labels = ['A(6, -4)', 'B(-2, -7)', f'Intersection(0, {intersection_y:.2f})']
for i, txt in enumerate(labels):
    plt.annotate(txt, (points[i, 0], points[i, 1]), textcoords="offset points", xytext=(0, 10), ha='center')

# Remove axis lines for cleaner look
ax = plt.gca()
ax.spines['left'].set_visible(False)
ax.spines['right'].set_visible(False)
ax.spines['top'].set_visible(False)
ax.spines['bottom'].set_visible(False)

plt.legend(loc='best')
plt.grid(True)
plt.axis('equal')
plt.show()

