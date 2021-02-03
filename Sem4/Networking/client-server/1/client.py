import socket

soc = socket.socket()

port = 3000

soc.connect(('127.0.0.1',port))
print(soc.recv(1024))
soc.close()