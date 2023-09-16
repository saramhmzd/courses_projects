import numpy as np
import random as rand


# remove space of first massage
def remove(s):
    return s.replace(" ", "")


# return a number that is divisible to 3
def fix_size(list_size):
    if list_size % 3 == 0:
        return list_size
    elif list_size % 3 == 1:
        return list_size + 2
    else:
        return list_size + 1


# generate a random 3*3 matrix
def generate_rand():
    a12 = rand.randint(1, 100)
    a13 = rand.randint(1, 100)
    a23 = rand.randint(1, 100)
    newKeyMatrix = np.array([[1, a12, a13], [0, 1, a23], [0, 0, 1]])
    return newKeyMatrix


KeyMatrix = np.array([[-5, -6, -59], [1, 1, 12], [2, 3, 22]])
KeyInverse = np.linalg.inv(KeyMatrix)

massage = input("enter your massage:")
SecretMassage = remove(massage)

# Convert String list to ascii values
# using list comprehension + ord()
AsciiList = [ord(ele) for sub in SecretMassage for ele in sub]
len_list = len(AsciiList)
m = int(fix_size(len_list) / 3)

# add 0 to end of list for making the length divisible to 3
while len_list < (m * 3):
    AsciiList.append(0)
    len_list += 1

# B matrix:
arr = np.array(AsciiList)
new_arr = arr.reshape(m, 3)
BMatrix = new_arr.transpose()
# print("This is our massage matrix:")
# print(BMatrix)

order = "yes"
CMatrix = np.array([])
while order == "yes":
    CMatrix = np.dot(KeyMatrix, BMatrix)
    # from 33 to 126
    CMatrix_ch = CMatrix % 93 + 33
    # print("This is a matrix that we should send:")
    # print(CMatrix_ch)

    cmatrix_list = list(CMatrix_ch.reshape(-1))
    CM = ''.join(map(chr, cmatrix_list))
    print("this is our massage that we should send:")
    print(CM)
    order = input("Do you want to employ another key matrix to encrypt the message?(if yes type 'yes')")
    if order == "yes":
        KeyMatrix = generate_rand()
        KeyInverse = np.linalg.inv(KeyMatrix)

# calculate our first massage by calculating our B matrix(first matrix)
first_matrix = np.dot(KeyInverse, CMatrix)
# print("this is our first matrix:")
# print(first_matrix)
t_first_matrix = first_matrix.transpose()
first_matrix_list = list(t_first_matrix.reshape(-1))
# print("this is our first matrix as list")
first_matrix_list = [round(x) for x in first_matrix_list]
first_matrix_list = [int(i) for i in first_matrix_list]
# print(first_matrix_list)

print("This is our first massage:")
YM = ''.join(map(chr, first_matrix_list))
print(YM)
