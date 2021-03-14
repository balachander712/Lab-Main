import socket

def crc_encode(data):
    g = [1,0,1,1]
    message = [int(bit) for bit in data]
    m = len(data)
    # append redundant bits
    for i in range(len(g) - 1):     
        message.append(0)

    # perform division
    while 1 in message[:m]:
        cur_shift = message.index(1)
        for i in range(len(g)):
            message[cur_shift + i] = g[i] ^ message[cur_shift + i]

    remainder = ''.join(str(e) for e in message[m:])
    message = data + remainder
    print(remainder)
    print('After encoding')
    print(message)
    return message

HOST = '127.0.0.1' 

PORT = 65431

try:
    s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    s.connect((HOST, PORT))
    message = '1101001100110101'
    encoded_message = crc_encode(message)
    s.sendall(encoded_message.encode('UTF-8'))  
    response = s.recv(1024)
    if response:
        print('Recieved response - >' , response.decode('UTF-8'), sep='\n')
    else:
        print('Server Closed')

except KeyboardInterrupt:
    s.close()
