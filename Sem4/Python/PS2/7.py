import numpy as np

def transpose(matrix,tr,N):
    for i in range(N):
        for j in range(N):
            tr[i][j] = matrix[j][i]


def isSymmetric(matrix,N):
    tr = [[0 for j in range(len(matrix[0]))] for i in range(len(matrix))]
    transpose(matrix,tr,N)
    for i in range(N):
        for j in range(N):
            if(matrix[i][j] != tr[i][j]):
                return False

    return True

def isStocastic(matrix,N):
    matrix = np.array(matrix)
    for x in matrix:
        if(float(sum(x)) == 1.0):
            if all(0 <= y <= 1.0 for y in x) is False:
                return False
            else:
                return False

    return True

def orthogonal(matrix):
    matrix = np.array(matrix)
    res1 = np.dot(matrix,matrix.T)
    res2 = np.dot(matrix.T,matrix)

    if idendity(res1) and idendity(res2):
        return True

    return False

def idendity(matrix):
    n = len(matrix)
    matrix = np.array(matrix)

    return np.allclose(np.identity(n),matrix)


if __name__ == '__main__':
    N = int(input('Enter the number of rows '))
    matrix = []

    for i in range(N):
        a = []
        for j in range(N):
            a.append(int(input()))
        matrix.append(a)

    if(isSymmetric(matrix,N)):
        print('Yes')
    else:
        print('No')