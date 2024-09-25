import numpy as np
import matplotlib.pyplot as plt

# Create a range of values for x
x = np.linspace(0, 2 * np.pi, 100)

# Calculate the sin(x) and cos(x) values
y_sin = np.sin(x)
y_cos = np.cos(x)

# Create a figure and axis
plt.figure(figsize=(8, 6))

# Plot sin(x)
plt.plot(x, y_sin, label='sin(x)', color='b', linestyle='-', marker='')

# Plot cos(x)
plt.plot(x, y_cos, label='cos(x)', color='r', linestyle='--', marker='')

# Add labels and title
plt.xlabel('x values (radians)')
plt.ylabel('y values')
plt.title('Plot of sin(x) and cos(x)')

# Add a legend
plt.legend()

# Show the plot
plt.grid(True)
plt.show()
