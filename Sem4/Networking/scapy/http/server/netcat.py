import socket
import time

def netcat(hn,p,content):
    sock=socket.socket(socket.AF_INET,socket.SOCK_STREAM)
    sock.connect((hn,p))
    sock.sendall(content)
    time.sleep(0.5)
    sock.shutdown(socket.SHUT_WR)
    ress=" "
    while True:
        data=sock.recv(1024)
        if(not data):
            break
        ress=data.decode()
    print(ress)
    sock.close()


if __name__=="__main__":
    hostname = '127.0.0.1'
    port = 3000
    content="GET FirstFile.html"
    netcat(hostname,port,content.encode())