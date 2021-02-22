import socket
import os

soc = socket.socket()

port = 3000

soc.connect(('127.0.0.1',port))
HOST = 'localhost'
ping = os.system('ping -c 1 ' + HOST)
print(f'ping is {ping}')
print(soc.recv(1024))
soc.close()