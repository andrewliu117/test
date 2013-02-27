#!/usr/bin/env python

import os
import time
import sys
sys.path.append("./fifo-py")

### thrift
from thrift import Thrift
from thrift.transport import TSocket
from thrift.transport import TTransport
from thrift.protocol import TBinaryProtocol
from thrift.server import TServer

### fifo
from fifo import FifoInterface
from fifo.ttypes import *
from fifo.FifoInterface import Iface

class FifoGetterHandler(Iface):
    def put(self, meta, value):
		print "meta = [%s], value=[%s]" %(meta,value)
		return 0


#if __name__ == "__main__":

handler = FifoGetterHandler()
processor = FifoInterface.Processor(handler)
transport = TSocket.TServerSocket("localhost",25435)
tfactory = TTransport.TBufferedTransportFactory()
pfactory = TBinaryProtocol.TBinaryProtocolFactory()
server = TServer.TThreadPoolServer(processor, transport, tfactory, pfactory)
server.setNumThreads(10)
print "start getter server"
server.serve()
