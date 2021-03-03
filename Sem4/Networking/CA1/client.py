import socket

#creating a TCP socket and connecting to the server
client = socket.socket()
client.connect(('localhost',9990))


while True:
    data = input('Enter the request :')
    client.send(data.encode('utf-8'))
    #getting the response from the server and printing
    server_response = client.recv(1024).decode('utf-8')
    print(server_response)

client.close()


#print(client.recv(1024).decode('utf-8'))
