
# Released under GNU GPL
# October 3, 2024
import numpy as np
import matplotlib.pyplot as plt
from scipy.integrate import quad

# Function for the parabola x = y^2 / 4
def parabola(y):
    return y**2 / 4

# Function for the vertical line x = 3
def line(y):
    return 3  # The x-value of the vertical line is constant for all y

# Function for the integrand (difference between the line and the parabola)
def integrand(y):
    return line(y) - parabola(y)

# Limits of integration (found by solving y^2 = 4x for x = 3 -> y = ±sqrt(12))
y_limit = np.sqrt(12)

# Calculate the area using definite integration between -sqrt(12) and sqrt(12)
area, error = quad(integrand, -y_limit, y_limit)

# Display the calculated area
print(f"The area enclosed by the parabola and the line is approximately {area:.2f} square units.")

# Generate y-values for plotting
y_values = np.linspace(-y_limit, y_limit, 400)

# Calculate corresponding x-values for the parabola and the line
x_parabola = parabola(y_values)
x_line = np.full_like(y_values, 3)  # Create an array of 3's with the same length as y_values

# Create the plot
plt.figure(figsize=(8, 6))

# Plot the parabola
plt.plot(x_parabola, y_values, label=r'$x = \frac{y^2}{4}$', color='blue')

# Plot the vertical line x = 3
plt.plot(x_line, y_values, label=r'$x = 3$', color='red')

# Shade the area between the parabola and the line
plt.fill_betweenx(y_values, x_parabola, x_line, where=(x_line >= x_parabola), 
                  color='lightgrey', alpha=0.5)

# Mark the intersection points (x = 3, y = ±sqrt{12})
plt.scatter([3, 3], [-y_limit, y_limit], color='black')
plt.text(3, y_limit, r'$(3, \sqrt{12})$', fontsize=12, ha='right')
plt.text(3, -y_limit, r'$(3, -\sqrt{12})$', fontsize=12, ha='right')

# Labeling the graph
plt.title('Area Enclosed by the Parabola and the Line')
plt.xlabel('x')
plt.ylabel('y')
plt.axhline(0, color='black', linewidth=0.5)  # x-axis
plt.axvline(0, color='black', linewidth=0.5)  # y-axis
plt.legend()
plt.grid(True)
plt.show()

