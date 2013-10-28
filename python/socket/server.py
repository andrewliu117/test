#!/usr/bin/env python
# -*- coding: utf-8 -*-
import socket

if __name__ == '__main__':
    sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    sock.bind(('localhost', 8001))
    sock.listen(5)
    while True:
        connection,address = sock.accept()
        try:
            connection.settimeout(5)
            while True:
                buf = connection.recv(1024)
                print buf
                if buf == '1':
                    connection.send('welcome to server!')
                elif buf == '0':
                    connection.close()
                    break
                else:
                    connection.send('please go out!')
        except socket.timeout:
            print 'time out'
            connection.close()
