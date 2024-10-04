# Program to plot the tangent of a parabola and find the enclosed area
# Code by GVV Sharma
# Released under GNU GPL
# August 19, 2024

import numpy as np
import matplotlib.pyplot as plt

import sys  # for path to external scripts
sys.path.insert(0, '/home/akhil-kothapalli/matgeo/codes/CoordGeo')  # path to my scripts

# local imports
from line.funcs import *
from triangle.funcs import *
from conics.funcs import *

# Define the conic parameters for the parabola y^2 = 4x
def conic_parameters():
    # V is the quadratic term matrix
    V = np.array([[0, 0],
                  [0, 1]])
    
    # u is the linear term vector
    u = np.array([-2, 0]).reshape(-1, 1)
    
    # f is the constant term
    f = 0
    
    return V, u, f

# Calculate points of intersection between the parabola and line
def intersection_points(x_val):
    # Solve y^2 = 4 * x for the given x = 3
    y_val = np.sqrt(4 * x_val)
    return np.array([x_val, y_val]), np.array([x_val, -y_val])

# Setting up the plot
fig = plt.figure()
ax = fig.add_subplot(111, aspect='equal')
num = 100
x = np.linspace(0, 3, num)  # Range of x values from 0 to 3

# Generating points for the parabola y^2 = 4x
y1 = np.sqrt(4 * x)
y2 = -np.sqrt(4 * x)

# Finding the points of intersection
point1, point2 = intersection_points(3)
y_max = point1[1]  # Maximum y value from intersection points
y_min = point2[1]  # Minimum y value from intersection points

# Generating points for the line x = 3, extended to meet the points of intersection
x_line = np.full_like(np.linspace(y_min, y_max, num), 3)
y_line = np.linspace(y_min, y_max, num)

# Plotting the parabola
plt.plot(x, y1, label=r'Parabola $y^2 = 4x$', color='r')
plt.plot(x, y2, color='r')

# Plotting the line x = 3, extended to the points of intersection
plt.plot(x_line, y_line, label=r'Line $x = 3$', color='b')

# Plotting the intersection points
plt.scatter(point1[0], point1[1], color='g', zorder=5, label='Intersection Points')
plt.scatter(point2[0], point2[1], color='g', zorder=5)

# Annotating the intersection points
plt.annotate(f'$({point1[0]}, {point1[1]:.2f})$', (point1[0], point1[1]), textcoords="offset points", xytext=(-10, 10), ha='center')
plt.annotate(f'$({point2[0]}, {point2[1]:.2f})$', (point2[0], point2[1]), textcoords="offset points", xytext=(-10, -15), ha='center')

# Filling the enclosed area between the parabola and the line
plt.fill_between(x, y1, y2, where=(x <= 3), color='cyan', alpha=0.5, label='Enclosed Area')

# Conic parameters
V, u, f = conic_parameters()

# Setting the plot labels and axis
tri_coords = np.block([[point1[0], point2[0]], [point1[1], point2[1]]])
plt.scatter(tri_coords[0,:], tri_coords[1,:], color='g')
vert_labels = ['$\mathbf{A}$','$\mathbf{B}$']
for i, txt in enumerate(vert_labels):
    plt.annotate(txt,  # label intersection points
                 (tri_coords[0,i], tri_coords[1,i]), 
                 textcoords="offset points", 
                 xytext=(-20,5), 
                 ha='center')

# Customizing axis and removing the spines
ax.spines['top'].set_color('none')
ax.spines['left'].set_position('zero')
ax.spines['right'].set_color('none')
ax.spines['bottom'].set_position('zero')

# Display legend, grid, and equal axis scaling
plt.legend(loc='best')
plt.grid()#minor 
plt.axis('equal')

# Show the plot
plt.show()

