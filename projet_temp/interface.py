#!/usr/bin/env python
# -*- coding: utf-8 -*-
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
        self.client = socket.socket(socket.AF_INET,socket.SOCK_STREAM)    
        
        try:    
            self.client.connect((self.ipAddress,port))
        except:
            print("Unable to connect")
        print(f"Connection on {self.port}")

        self.clientName = " "
        self.thread_receiving = threading.Thread(target =self.receiving)
        self.thread_sending = threading.Thread(target =self.sending)
        self.thread_receiving.start()
        self.thread_sending.start()

        self.thread_sending.join()
        self.thread_receiving.join()


    def sending(self):
        while True:
            message = input(">>send:")
            if "::STOP" in message:
                print("Signal STOP received, end sending thread")
                break
            message = message + "\n"
            self.client.send(message.encode())

    def receiving(self):
        while True:
            data = self.client.recv(1024).decode('utf-8')
            if f"LFT {self.clientName}" in data:
                break
            print(f"\n>>received:{data}")

        '''
        print(f"{self.client.recv(1024).decode('utf-8')}")#WHO
        while(" " in self.clientName):
            self.clientName = input("Entrez votre pseudo: ")
        self.client.send(f"IAM {self.clientName}".encode())
        print(f"Pseudo choisi:{self.clientName}")
        print(f"rmsg: {self.client.recv(1024).decode('utf-8')}")
        print("before")
        self.client.send(f"MSG {input()}".encode())
        print("after")
        print(f"{self.client.recv(1024).decode('utf-8')}")#WHO
        print("end")
'''

            
def main():
    s = Client("pablo.rauzy.name",4567)
    #s = Client("localhost",4567)



if __name__ == '__main__':
    main()
