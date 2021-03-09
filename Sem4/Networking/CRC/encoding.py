g = [1,0,1,1]
data = '11010011101100'
message = [int(bit) for bit in data]
m = len(data)
# append redundant bits
for i in range(len(g) - 1):     
    message.append(0)

print('Before')
print(data)

# perform division
while 1 in message[:m]:
    cur_shift = message.index(1)
    for i in range(len(g)):
        message[cur_shift + i] = g[i] ^ message[cur_shift + i]

message = data + ''.join(str(e) for e in message[m:])
print('After')
print(message)  