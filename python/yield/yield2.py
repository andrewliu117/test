#!/usr/bin/env python
# -*- coding: utf-8 -*-

def inc():
    i = 10
    while i < 10:
        print i
        yield i
        i += 1

if __name__ == '__main__':
    j = 0;
    while j < 10:
        print inc().next()
        j += 1
