import socket
import os 
import subprocess


sock = socket.socket()
sock.bind(('localhost',9991))
sock.listen(10)

while True:
    client,addr = sock.accept()
    option = client.recv(1024).decode()
    print(option)

    if option == 'R':
        routing_tables = subprocess.check_output(['ip route list'],shell=True)
        client.send(routing_tables)
    elif option == 'S':
        tcp_sockets = subprocess.check_output(['ss -s | grep TCP'],shell=True)
        client.send(tcp_sockets)
    elif option == 'A':
        arp_cache = subprocess.check_output(['arp -a'],shell=True)
        client.send(arp_cache)

client.close()