import numpy as np
import random as rand
from numpy import linalg as la


def norm2(m):
    MaxP = 0.0
    MaxP2 = 0.0
    for i in range(1, 4000):
        r = rand.uniform(0, 1)
        t = rand.uniform(0, 1)
        u = rand.uniform(0, 1)
        if i <= 1000:
            x = np.array([[r], [(1 - r ** 2) ** (1 / 2)]])
            y = np.array([[t], [(1 - t ** 2) ** (1 / 2)]])
            z = np.array([[u], [(1 - u ** 2) ** (1 / 2)]])
        elif i <= 2000:
            x = np.array([[-r], [(1 - r ** 2) ** (1 / 2)]])
            y = np.array([[-t], [(1 - t ** 2) ** (1 / 2)]])
            z = np.array([[-u], [(1 - u ** 2) ** (1 / 2)]])
        elif i <= 3000:
            x = np.array([[-r], [(r ** 2 - 1) ** (1 / 2)]])
            y = np.array([[-t], [(t ** 2 - 1) ** (1 / 2)]])
            z = np.array([[-u], [(u ** 2 - 1) ** (1 / 2)]])
        else:
            x = np.array([[r], [(r ** 2 - 1) ** (1 / 2)]])
            y = np.array([[t], [(t ** 2 - 1) ** (1 / 2)]])
            z = np.array([[u], [(u ** 2 - 1) ** (1 / 2)]])
        valP = la.norm(np.dot(m, x))
        valP2 = la.norm(np.dot(m, y))
        valP3 = la.norm(np.dot(m, z))
        if MaxP < valP:
            MaxP = valP
        MaxP2 = max(valP, valP2, valP3, MaxP2)
    return MaxP, MaxP2


Str = input("enter 4 element of matrix(split them with space):")
str_list = list(map(float, Str.split(' ')))
A = np.array([[str_list[0], str_list[1]], [str_list[2], str_list[3]]])

print("This is norm 2 A(by norm function in python):")
print(la.norm(A, 2))
print("The first item is p result and the second item is p' result:")
print(norm2(A))
print("p' result is closer to result of norm function in python or it's equal to p result ")
