import numpy as np

def getInverse(matrix):
    m = np.array(matrix)
    inverse = np.linalg.inv(m)
    print(inverse)



if __name__ == '__main__':
    R = int(input('Enter the number of rows '))
    C = int(input('Enter the number of cols '))
    matrix = []

    for i in range(R):
        a = []
        for j in range(C):
            a.append(int(input()))
        matrix.append(a)

    getInverse(matrix)