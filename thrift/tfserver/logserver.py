#!/usr/bin/env python
import sys
sys.path.append('./gen-py')
from logservice import logservice
import subprocess

from thrift.transport import TSocket
from thrift.transport import TTransport
from thrift.protocol import TBinaryProtocol
from thrift.server import TServer

class logserviceHandler:
	def getlistlogs(self, putlist, listlen):
		getmap = {}
		if len(putlist) == 0:
			#getmap["url"]=["NULL"]
			return getmap
		for i in putlist:
			getlist = []
			args="../urlfinder.py -l %d %s" % (listlen, i)
			p = subprocess.Popen(args, stdout=subprocess.PIPE, shell = True)  
			getlist.extend(p.stdout.readlines())
			getmap[i] = getlist;
		return getmap

	def getlogs(self, putlist):
		getmap = {}
		if len(putlist) == 0:
			#getmap["url"]=["NULL"]
			return getmap
		for i in putlist:
			getlist = []
			args="../urlfinder.py %s" % i
			p = subprocess.Popen(args, stdout=subprocess.PIPE, shell = True)  
			getlist.extend(p.stdout.readlines())
			getmap[i] = getlist;
		return getmap
			
handler = logserviceHandler()
processor = logservice.Processor(handler)
transport = TSocket.TServerSocket("10.156.24.22",19090)
tfactory = TTransport.TBufferedTransportFactory()
pfactory = TBinaryProtocol.TBinaryProtocolFactory()

server = TServer.TSimpleServer(processor, transport, tfactory, pfactory)

# You could do one of these for a multithreaded server
#server = TServer.TThreadedServer(processor, transport, tfactory, pfactory)
#server = TServer.TThreadPoolServer(processor, transport, tfactory, pfactory)

print 'Starting the server...'
server.serve()
print 'done.'

