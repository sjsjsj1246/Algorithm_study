import numpy as np

def f(r, x):
    if np.any(np.logical_and(x >= 0, x <= 1/2)):
        return r*x
    elif np.any(np.logical_and(x > 1/2, x <= 1)):
        return r*(1-x)