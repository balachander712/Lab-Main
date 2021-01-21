import numpy as np

def euclidDist(u,v):
    u = np.array(u)
    v = np.array(v)

    euclidDist = np.linalg.norm(u - v)

    return euclidDist

def unitVector(vector):
    return vector / np.linalg.norm(vector)

def cosineAngle(u,v):
    u1 = unitVector(u)
    v1 = unitVector(v)

    angle =  np.arccos(np.clip(np.dot(u1,v1),-1.0,1.0))
    angle_deg = np.degrees(angle)
    return np.cos(angle_deg)

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

    euclid_dist = euclidDist(u,v)
    cosine_angle = cosineAngle(u,v)

    print(f'The Euclidean vector distance between {u} and {v} is {euclid_dist}')
    print(f'The cosine angle between {u} and {v} is {cosine_angle}')





