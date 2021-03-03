import socket
import threading

HOST = 'localhost'
PORT = 9999

name = input('Enter your name ')

client = socket.socket()
client.connect((HOST,PORT))

def recieve():
    while True:
        try:
            message = client.recv(1024).decode('utf-8')
            if message == 'NAME':
                client.send(name.encode('utf-8'))
            else:
                print(message)

        except:
            print('ERROR!!! Closing the connection :(')
            client.close()
            break

def write():
    while True:
        message = name + ":" + input(' ')
        client.send(message.encode('utf-8'))


recieve_thread = threading.Thread(target=recieve)
recieve_thread.start()

write_thread = threading.Thread(target=write)
write_thread.start()