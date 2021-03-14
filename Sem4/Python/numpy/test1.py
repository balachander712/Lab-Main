import numpy as np

csv_array = np.array([1,2,3,4,5])
np.savetxt('newfile.csv',csv_array)

b = np.loadtxt('newfile.csv')
print(b)