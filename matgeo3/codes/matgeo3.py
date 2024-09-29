import numpy as np
import matplotlib.pyplot as plt

# Define the functions for the parabola and the line
def parabola(x):
    return x ** 2

def line(x):
    return x + 2

# Calculate the intersection points by solving x^2 = x + 2
# x^2 - x - 2 = 0 -> (x - 2)(x + 1) = 0 -> x = 2, -1
x_intersection = np.array([-1, 2])

# Create the range for x-values from -1 to 2
x_values = np.linspace(-1, 2, 400)

# Calculate y-values for the parabola and the line
y_parabola = parabola(x_values)
y_line = line(x_values)

# Create the plot
plt.figure(figsize=(8, 6))
plt.plot(x_values, y_parabola, label=r'$y = x^2$', color='blue')
plt.plot(x_values, y_line, label=r'$y = x + 2$', color='red')

# Shade the region between the parabola and the line
plt.fill_between(x_values, y_parabola, y_line, where=(y_line >= y_parabola), interpolate=True, color='lightgrey', alpha=0.5)

# Mark the intersection points
plt.scatter(x_intersection, parabola(x_intersection), color='black')
for x, y in zip(x_intersection, parabola(x_intersection)):
    plt.text(x, y, f'({x}, {y})', fontsize=12, ha='right')

# Labeling the graph
plt.title('Area Enclosed by the Parabola and the Line')
plt.xlabel('x')
plt.ylabel('y')
plt.axhline(0, color='black',linewidth=0.5)
plt.axvline(0, color='black',linewidth=0.5)
plt.legend()
plt.grid(True)
plt.show()

