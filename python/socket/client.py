#!/usr/bin/env python
# -*- coding: utf-8 -*-
import socket
import time

if __name__ == '__main__':
    sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    sock.connect(('localhost', 8001))
    #time.sleep(2)
    sock.send('1')
    print sock.recv(1024)
    time.sleep(1)
    sock.send('this is it 1')
    print sock.recv(1024)
    time.sleep(1)
    sock.send('this is it 2')
    print sock.recv(1024)
    time.sleep(1)
    sock.send('this is it 3')
    print sock.recv(1024)
    time.sleep(1)
    sock.send('this is it 4')
    print sock.recv(1024)
    time.sleep(1)
    sock.send('this is it 5')
    print sock.recv(1024)
    time.sleep(1)
    sock.send('0')
    print sock.recv(1024)
    sock.close()
