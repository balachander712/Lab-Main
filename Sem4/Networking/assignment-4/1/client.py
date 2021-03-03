import socket

client = socket.socket()
client.connect(('localhost',9991))


print('R - Get server routing table')
print('S - Get number of UDP sockets')
print('A - Get server ARP cache')

option = input('')
client.send(bytes(option,'utf-8'))
print(client.recv(1024).decode('utf-8'))
