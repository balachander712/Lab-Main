# -*- coding: utf-8 -*-
"""
Created on Tue Dec 21 13:53:29 2021

@author: 19pw06
"""

import socket
import threading
import os
import hashlib

ServerSocket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
host = 'localhost'
port = 5555
ThreadCount = 0

try:
    ServerSocket.bind((host, port))
except socket.error as e:
    print(str(e))
    
print('Waiting for connection...')
ServerSocket.listen(5)
HashTable = {}

def threaded_client(connection):
    connection.send(str.encode('ENTER USERNAME : '))
    name = connection.recv(2048)
    connection.send(str.encode('ENTER PASSWORD : '))
    password = connection.recv(2084)
    name = name.decode()
    password = password.decode()
    password = hashlib.sha256(str.encode(password)).hexdigest()
    
    if name not in HashTable:
        HashTable[name] = password
        connection.send(str.encode('Registration successful'))
        print('Registered : ' , name)
        
    else:
        if HashTable[name] == password:
            connection.send(str.encode('Conncection successful'))
            print('Connection', name)
        else:
            connection.send(str.encode('Login Failed'))
            print('Connection Denied', name)
    
    connection.close()
    

while True:
    Client, addr = ServerSocket.accept()
    client_handler = threading.Thread(
            target = threaded_client,
            args = (Client,)
            )
    client_handler.start()
    ThreadCount += 1
    print('Connection Request : ' + str(ThreadCount))
    

ServerSocket.close()
        
        
        
        
        
        
        
        
        
        
        
        