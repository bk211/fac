import sys
import socket
import threading
import time


class Client:
    def __init__(self,hostName,port):
        self.hostName = hostName
        self.ipAddress = socket.gethostbyname(hostName)
        self.port = port
        print(f"IP address of the host name {self.hostName} is: {self.ipAddress}")
        self.server = socket.socket(socket.AF_INET,socket.SOCK_STREAM)    
        try:    
            self.server.connect((self.ipAddress,port))
        except:
            print("Unable to connect")
        print(f"Connection on {self.port}")

def main():
    s = Client("pablo.rauzy.name",4567)



if __name__ == '__main__':
    main()
