import socket

def crc_decode(data):
    # x4 + x2 + x1 + 1  # take any polynomial you wish and just fill coeff
    print(data)
    g = [1,0,1,1]
    message = [int(bit) for bit in data]
    m = len(data) - len(g) + 1
    # perform division
    while 1 in message[:m]:
        cur_shift = message.index(1)
        for i in range(len(g)):
            message[cur_shift + i] = g[i] ^ message[cur_shift + i]

    print(message[m:])
    is_corrupted = 1 in message[m:]

    if is_corrupted:
        print('Corrupted')
    else:
        print('No error, data recieved is')
        print(data[:m])
    


HOST = '127.0.0.1'

PORT = 65431 

with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
    s.bind((HOST,PORT))
    s.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)    
    s.listen()

    while True:
        print("Listening for new client..")
        conn, addr = s.accept()
        print("New client connected!")

        with conn:
            print('Connected by', addr)
        
            while True:
                data = conn.recv(1024)
                data = data.decode('utf-8')
                response = 'OK'.encode('utf-8')
                if data:
                    crc_decode(data)
                    conn.sendall(response)
                
                else:
                    print("client left")
                    conn.close()
                    break
            