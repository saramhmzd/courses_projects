import numpy as np
import random as rand
from numpy import linalg as la


def norminf(m):
    MaxP = 0.0
    for i in range(1, 10000):
        r = rand.uniform(-1, 1)
        if i <= 2500:
            x = np.array([[1.0], [r]])
        elif i <= 5000:
            x = np.array([[r], [1.0]])
        elif i <= 7500:
            x = np.array([[-1.0], [r]])
        else:
            x = np.array([[r], [-1.0]])
        valP = la.norm(np.dot(m, x), np.inf)
        if MaxP < valP:
            MaxP = valP
    return MaxP


Str = input("enter 4 element of matrix(split them with space):")
str_list = list(map(float, Str.split(' ')))
A = np.array([[str_list[0], str_list[1]], [str_list[2], str_list[3]]])

print("This is norm inf A:")
print(la.norm(A, np.inf))
print(norminf(A))

