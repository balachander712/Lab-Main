data = input('Enter the first data word ')
list(data)

r = 0

while((len(data) + r + 1) > pow(2,r)):
    r = r + 1

binary = [0] * (len(data) + r)

j = len(data) - 1
p = 0

for i in range(0, len(data) + r):
    if (pow(2,p) - 1 == i):
        p = p + 1
    else:
        binary[i] = data[j]
        j = j - 1


#Doing even parity
#As it is mentioned in the question to use even parity

parity = []

for j in range(1, r+1):
    list1 = []
    for i in range(1, len(data) + r + 1):
        x = format(i,"b")
        if(j <= len(x) and x[0-j] == 'i' and binary[i-1] == 1):
            list1.append()
        if(len(list1)%2==0):
            parity.append(0)
        else:
            parity.append(1)


j = 0
p = 0

for i in range(0, len(data) + r):
    if(pow(2,p) - 1 == i):
        binary[i] = parity[j]
        p = p + 1
        j = j + 1

binary.reverse()
print(binary)
