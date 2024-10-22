import numpy as np
import sympy as sp


# Derivatives
# Define symbol
x = sp.Symbol('x')

# Define a function
f = x**3

# Differentiate the function
derivative = sp.diff(f, x)

print(derivative)
