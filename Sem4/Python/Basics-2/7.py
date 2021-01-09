arrA = [1,2,4,5,67,89,54,32,43,21]
arrB = [54,65,32,65,21,65,23,5,1,6,7]

setA = set(arrA)
setB = set(arrB)

sorted(setA)
sorted(setB)

if setA == setB:
    print('Both sets are equal')
else:
    arrB1 = [value for value in arrA if value not in arrB]
    arrB2 = [value for value in arrB if value not in arrA]
    print(arrB1)
    print(arrB2)