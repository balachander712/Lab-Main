import socket
import os

soc = socket.socket()
print('Connected Socket..')

port = 3000

soc.bind(('',port))
soc.listen(5)

while True:
    client,addr = soc.accept()
    print(f'Connection recieved from {addr}..')
    msg = client.recv(1024).decode('utf-8')

    arr = list(msg)
    arr = list(map(int,arr))
    arr.reverse()
    ans_parity = []

    r = 0
    while((len(arr) + 1) > pow(2,r)):
        r = r + 1

    for j in range(1, r+1):
        sum = 0
        for j in range(1, r+1):
            x = format(j,"b")
            if(j <= len(x) and x[0-j] == '1'):
                sum += arr[j-1]

        if(sum%2 == 0):
            ans_parity.append(0)
        else:
            ans_parity.append(1)
        
        ans_parity.reverse()
        print(ans_parity)
        temp = ''.join(str(x) for x in ans_parity)
        num = int(temp,2)
        if(num == 0):
            print('NO ERROR')
            client.send(bytes('NO ERROR'),'utf-8')
        else:
            print('ERROR at INDEX => ' + str(num))
            client.send(bytes('ERORR AT INDEX =>' + str(num) + 'utf-8'))

    client.close()