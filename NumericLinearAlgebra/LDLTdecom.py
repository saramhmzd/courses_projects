import numpy as np

# Matrix A n*n
A = [[1, 1, 4, -1], [1, 5, 0, -1], [4, 0, 21, -4], [-1, -1, -4, 10]]
PD = False
try:
    L = np.linalg.cholesky(A)
    LT = L.T
    PD = True
except np.linalg.LinAlgError as error:
    print(error)

if PD:
    # L_D_L_T
    n = len(A)

    D = np.zeros([n, n], dtype=float)
    for i in range(0, n):
        D[i][i] = LT[i][i] ** 2
        d = LT[i][i]
        for j in range(i, n):
            LT[i][j] = LT[i][j] / d

    print("L' :")
    print(L)

    print("D :")
    print(D)

    print("LT' :")
    print(LT)

    LD = np.dot(L, D)
    print("L'DLT' :")
    print(np.dot(LD, LT))
