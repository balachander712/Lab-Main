import numpy as np

if __name__ == '__main__':
    n = int(input('Enter the value of n '))
    print('Enter u vector ')
    u = []
    v = []
    for i in range(0,n):
        vector = int(input(''))
        u.append(vector)

    print('Enter v vector ')

    for i in range(0,n):
        vector = int(input(''))
        v.append(vector)

    u = np.array(u)
    v = np.array(v)

    euclidDist = np.linalg.norm(u - v)
    print(f'The Euclidean vector distance between {u} and {v} is {euclidDist}')