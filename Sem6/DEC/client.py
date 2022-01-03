import socket

client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
host = 'localhost'
port = 5555

client.connect((host, port))
response = client.recv(2048)
name = input(response.decode())
client.send(str.encode(name))
response = client.recv(2048)

password = input(response.decode())
client.send(str.encode(password))

response = client.recv(2048)
response = response.decode()

client.close()