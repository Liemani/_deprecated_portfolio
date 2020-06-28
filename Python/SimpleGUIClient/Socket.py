//********************************************
// title = "Socket"
// made by Lieman at 2020.06.26
//
// description:
//	Socket class
//********************************************





import socket
import sys


class Socket:
    def __init__(self, server_address):
        self.socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        self.socket.connect(server_address)

    def write(self, message):
        self.socket.send(bytes(message, 'utf-8'))

    def close(self):
        print('Closing connection', sys.stderr)
        self.socket.close()
