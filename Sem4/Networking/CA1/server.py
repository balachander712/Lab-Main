import socket
import os 
import subprocess


#Creatinf a TCP socket - by defalut the socket function returns TCP socket
sock = socket.socket()
sock.bind(('localhost',9990))
#listening to clients - the server can handle a maximum of 10 clients at a time
sock.listen(10)

#empty dict to store the local MAC-IP table
MAC_LIST = dict()

while True:

    #accepting the client requests
    client,addr = sock.accept()

    data = client.recv(1024).decode('utf-8')
    print(data)

    if data.startswith('DOMAIN_NAME'):
        option = data.split(' ')
        #using dig command to get the ip address of the domain name
        ip_addr = subprocess.check_output('dig +short ' + option[1], shell=True)
        client.send(ip_addr)

    elif data.startswith('MAC'):
        #getting the MAC address of the client and updating in the server's local MAC-IP table
        option = data.split(' ')
        MAC_LIST.update({option[1]:addr[0]})
        print(MAC_LIST)
        client.sendall(bytes('Table updated','utf-8'))

    elif data == 'table':
        print('Sending the client the MAC table')
        client.sendall(bytes(str(MAC_LIST), 'utf-8'))

    elif data == 'break':
        break

    else:
        print('Command not found ')


client.close()