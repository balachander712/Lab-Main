numbers = [12,24,35,24,88,120,155]
newList = []

for i in numbers:
    if int(i) != 24:
        newList.append(i)

print(newList)