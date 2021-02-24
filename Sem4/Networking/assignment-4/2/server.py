import socket
import threading


HOST = 'localhost'
PORT = 9999

server = socket.socket()
server.bind((HOST,PORT))
server.listen()

clients = []
names = []

def broadcast(message):
    for client in clients:
        client.send(message)


def handle(client):
    while True:
        try:
            message = client.recv(1024)
            broadcast(message)
        except:
            index = clients.index(client)
            clients.remove(client)
            client.close()
            name = names[index]
            broadcast(f'{name} left the chat...'.encode('utf-8'))
            names.remove(name)
            break


def recieve():
    while True:
        client,address = server.accept()
        print(f'Connected with {str(address)}')

        client.send('NAME'.encode('utf-8'))
        name = client.recv(1024).decode('utf-8')
        names.append(name)
        clients.append(client)

        print(f'{name} is here')
        broadcast(f'{name} joined the chat '.encode('utf-8'))
        client.send('Connected to the server'.encode('utf-8'))

        thread = threading.Thread(target=handle, args=(client,))
        thread.start()


recieve()