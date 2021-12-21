import socket

client_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

msg_to_server = input("Enter your message")
client_socket.sendto((msg_to_server+'1').encode(), ('10.1.66.53', 12385))

msg_from_server =  client_socket.recvfrom(1024)
print('Message from server', msg_from_server[0].decode())