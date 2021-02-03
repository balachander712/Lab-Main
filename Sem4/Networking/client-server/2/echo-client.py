import socket
import sys

sock = socket.socket(socket.AF_INET,socket.SOCK_DGRAM)

server_addr = ('localhost',10000)
message = 'Hey there'

try:
    print(f'sending{message}')
    sent = sock.sendto(message,server_addr)

    print('waiting to receive..')
    data,server = sock.recvfrom(4096)
    print(f'received {len(data)} byted of data from {server}')

finally:
    print('closing sockets...')
    sock.close()