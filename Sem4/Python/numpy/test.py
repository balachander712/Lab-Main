import numpy as np 

a = np.array([1, 2, 3, 4, 5, 6])
np.save('filename',a)

b = np.load('filename.npy')
print(b)