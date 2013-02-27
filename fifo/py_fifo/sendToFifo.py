#!/usr/bin/env python

import sys
import os
import time;

sys.path.insert(0, "/home/liuhongjiang/test/fifo_test/fifo_js/public")
sys.path.append("./gen-py")

from thrift import Thrift
from thrift.transport import TSocket
from thrift.transport import TTransport
from thrift.protocol import TBinaryProtocol

### fifo
from fifo import FifoInterface
from fifo.ttypes import *

### json
import json

#if __name__ == "__main__":
transport = TSocket.TSocket('localhost', 25556)
transport = TTransport.TBufferedTransport(transport)
protocol = TBinaryProtocol.TBinaryProtocol(transport)
client = FifoInterface.Client(protocol)
transport.open()
i = 0;

while i < 10:
	rt = client.put("no", "b")
	if int(rt) == 1:
		print "success in sending :%d" %(i)
	else:
		print "faild in sending :%d. error code:%s" %(i, rt)

transport.close()
