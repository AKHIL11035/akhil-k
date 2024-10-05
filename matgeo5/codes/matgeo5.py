#Code by GVV Sharma
#Released under GNU GPL
#August 10, 2020
#Revised July 31, 2024

import numpy as np
import matplotlib.pyplot as plt
from numpy import linalg as LA

import sys                                          #for path to external scripts
sys.path.insert(0, '/home/akhil-kothapalli/matgeo/codes/CoordGeo')        #path to my scripts

# Labeling points
def label_pts(G_v, vert_labels): 
    for i, txt in enumerate(vert_labels):
        plt.annotate(txt,              # Text to annotate
                     (G_v[0, i], G_v[1, i]),  # Coordinates for the point
                     textcoords="offset points", # Positioning the text relative to the point
                     xytext=(0, 10),    # Offset from point (x,y)
                     ha='center')       # Horizontal alignment: can be 'left', 'right', or 'center'

# Function to generate line points
def line_gen(A, B):
    len = 100
    dim = A.shape[0]
    x_AB = np.zeros((dim, len))
    lam_1 = np.linspace(0, 1, len)
    for i in range(len):
        temp1 = A + lam_1[i] * (B - A)
        x_AB[:, i] = temp1.T
    return x_AB

# Function to find the intersection of two lines
def line_isect(n1, c1, n2, c2):
    N = np.block([n1, n2]).T
    p = np.zeros((2, 1))
    p[0] = c1
    p[1] = c2
    P = np.linalg.solve(N, p)
    return P

# Coefficients for the lines: 3x - 2y + 1 = 0, 2x + 3y - 21 = 0, x - 5y + 9 = 0
n1 = np.array([[3], [-2]])
c1 = -1
n2 = np.array([[2], [3]])
c2 = 21
n3 = np.array([[1], [-5]])
c3 = -9

# Find intersection points of the lines
P1 = line_isect(n1, c1, n2, c2)  # Intersection of line 1 and line 2
P2 = line_isect(n2, c2, n3, c3)  # Intersection of line 2 and line 3
P3 = line_isect(n3, c3, n1, c1)  # Intersection of line 3 and line 1

# Stack intersection points for labeling
G_v = np.hstack((P1, P2, P3))

# Vertex labels
vert_labels = ['P1', 'P2', 'P3']

# Generate line segments
x12 = line_gen(P1, P2)
x23 = line_gen(P2, P3)
x31 = line_gen(P3, P1)

# Plot the lines
plt.plot(x12[0, :], x12[1, :], label='$3x - 2y + 1 = 0$ and $2x + 3y - 21 = 0$')
plt.plot(x23[0, :], x23[1, :], label='$2x + 3y - 21 = 0$ and $x - 5y + 9 = 0$')
plt.plot(x31[0, :], x31[1, :], label='$x - 5y + 9 = 0$ and $3x - 2y + 1 = 0$')

# Fill the region inside the bounded area
plt.fill([P1[0, 0], P2[0, 0], P3[0, 0]], [P1[1, 0], P2[1, 0], P3[1, 0]], 'grey', alpha=0.3)

# Plot intersection points
plt.scatter(P1[0], P1[1], color='red')
plt.scatter(P2[0], P2[1], color='red')
plt.scatter(P3[0], P3[1], color='red')

# Annotate intersection points using the provided label_pts function
label_pts(G_v, vert_labels)

# Formatting plot
plt.xlabel('$x$')
plt.ylabel('$y$')
plt.legend(loc='best')
plt.grid(True)
plt.axis('equal')
plt.title('Region Bounded by the Lines')

# Show plot
plt.show()

