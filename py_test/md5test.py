#!/usr/bin/env python

import hashlib, struct
import binascii
url = "http://v.pptv.com/show/iceXBP6cNfbvkQKkPfw.html"
md5str = "08c26297025d3f3d7f9208528c238f8c"


md5 = hashlib.md5()
md5.update(url)
x = md5.digest()
y = struct.unpack('ll', x)
print y[0]
print y[1]
urlsign = y[0] ^ y[1]
print urlsign
print md5.hexdigest()

print "-----------------------"
lo = binascii.a2b_hex(md5str) 
y = struct.unpack('ll', lo)
print y[0]
print y[1]
urlsign = y[0] ^ y[1]
print urlsign

