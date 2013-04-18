#!/usr/bin/env python
# -*- coding: utf-8 -*-

import struct

fp = open("b.txt", "rb")
for i in range(10):
    for j in range(10):
        (a,) = struct.unpack("i", fp.read(4))
        print a,
    print " "
fp.close()
