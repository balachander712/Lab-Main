nums = [6,3]
maxList = 17
x = 0
y = maxList
minVal = 0
while True:

    if x == int(maxList/2) or y == int(maxList/2):
        break

    if x + y == maxList:
        minVal = min(x,y)
        x = x+1
        y = y-1


    

print(minVal)