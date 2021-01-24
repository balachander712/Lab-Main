import socket

soc = socket.socket()
print('Connected Socket..')

port = 3000

soc.bind(('',port))
soc.listen(5)

while True:
    conn,addr = soc.accept()
    print(f'Connection recieved from {addr}..')
    msg = 'Connected with server'
    conn.sendall(msg.encode('utf-8'))
    conn.close()
