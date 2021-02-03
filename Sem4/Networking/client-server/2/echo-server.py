import socket
import sys

sock = socket.socket(socket.AF_INET,socket.SOCK_DGRAM)

server_addr = ('127.0.0.1',10000)
print(f'starting upon {server_addr}...')
sock.bind(server_addr)

while True:
    print('waiting to receive message...')
    data,addr = sock.recvfrom(4096)

    print(f'received {len(data)} from {addr}')
    print(data)

    if data:
        sent = sock.sendto(data,addr)
        print(f'sent {len(data)} back to {sent,addr}')