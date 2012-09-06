#!/usr/bin/env python

import sys
sys.path.append('./gen-py')

from logservice import logservice

from thrift import Thrift
from thrift.transport import TSocket
from thrift.transport import TTransport
from thrift.protocol import TBinaryProtocol

try:
	# Make socket
	transport = TSocket.TSocket("10.156.24.22", 19090)

	# Buffering is critical. Raw sockets are very slow
	transport = TTransport.TBufferedTransport(transport)

	# Wrap in a protocol
	protocol = TBinaryProtocol.TBinaryProtocol(transport)

	# Create a client to use the protocol encoder
	client = logservice.Client(protocol)

	# Connect!
	transport.open()

	putlist=["http://www.tudou.com/v/N5WBrcNJRIo/v.swf", "http://www.tudou.com/programs/view/yHGd7ISWXMY/", "c"]
		
	getmap = client.getlogs(putlist)
	for i in getmap:
		print "-------------"
		print i
		for j in getmap[i]:
			print j

	print "#######################################"
	print "##the follow log is list with 3 line:##"
	print "#######################################"

	getmap = client.getlistlogs(putlist, 3)
	for i in getmap:
		print "-------------"
		print i
		for j in getmap[i]:
			print j

except Thrift.TException, tx:
	print '%s' % (tx.message)

