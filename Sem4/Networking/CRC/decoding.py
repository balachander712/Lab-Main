g = [1,0,1,1]
data = '11010011101100100'
message = [int(bit) for bit in data]
m = len(data) - len(g) - 1
# perform division
while 1 in message[:m]:
    cur_shift = message.index(1)
    for i in range(len(g)):
        message[cur_shift + i] = g[i] ^ message[cur_shift + i]

is_corrupted = 1 in message[m:]

if is_corrupted:
    print('Corrupted')
else:
    print('No error, data recieved is')
    print(data[:m])