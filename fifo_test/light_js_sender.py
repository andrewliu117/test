#!/usr/bin/env python
#-*- coding:utf-8 -*-

import sys
import os
import time;

sys.path.append("./fifo-py")
#from set_path import *

### logging
import logging
import logging.config
logging.config.fileConfig((os.path.join(os.path.dirname(__file__), '../conf/fifo_js_sender.conf')))

### thrift
from thrift import Thrift
from thrift.transport import TSocket
from thrift.transport import TTransport
from thrift.protocol import TBinaryProtocol

### fifo
from fifo import FifoInterface
from fifo.ttypes import *

### json
import json

def geturls(fn, lno):
	fp = open(fn, 'r')
	for line in fp:
		if lno == 0:
			field = line.split()
			value = json.loads(field[1])	
			if "playcnt" not in value:
				yield value[url]  
		else:
			lno -= 1


def getnextfile(cur_fn):
	file_list = os.listdir("../data/")	
	file_list.sort()
	if cur_fn == "":
		return file_list[0]
	next_fn = ""
	find = False
	for fn in file_list:
		if find:
			next_fn = fn
			break
		if fn == cur_fn: 
			find = True
	return next_fn

def processurl(client_, url):
	meta = {}
	meta["js_type"] = "light_js"
	value = {}
	value["url"] = url

	try:
		#print "meta=[%s],value[%s]" %(json.dumps(meta), json.dumps(value))
		rt = client_.put(json.dumps(meta), json.dumps(value))
		if int(rt) == 1:
			logging.info("success in sending url:%s" %value["url"])
		else:
			logging.error("faild in sending url:%s. error code%s" %(value["url"], rt))
	except:
		logging.error("exception in sending url:%s" %value["url"])


if __name__ == "__main__":
	transport = TSocket.TSocket('10.156.24.11', 40301)
	transport = TTransport.TBufferedTransport(transport)
	protocol = TBinaryProtocol.TBinaryProtocol(transport)
	client = FifoInterface.Client(protocol)

    # read index file
	if os.path.isfile('log.index'):
		idxfile = open('log.index','r')
		idxlines = idxfile.readlines()
		if len(idxlines) != 1:
			print "log.index file isn't normal"
			sys.exit()
		idxline = idxlines[0]
		idxlist = idxline.split()
		log_filename = idxlist[0]
		log_lines = int(idxlist[1])
		idxfile.close()
	else:
    #start from the begining
		log_filename = getnextfile("")
		log_lines = 0

	transport.open()

	run = True
	while run:
		fp = open("../data/"+log_filename, 'r')
		rno = 0
		for line in fp:
			rno +=1
			if log_lines < rno:
				field = line.split("\t")
				try:
					value = json.loads(field[1])	
					if "playcnt" not in value: 
						#print "playurl =", value["playurl"]
						processurl(client, value["playurl"])
				except:
					logging.error("json load error:%s" %value["playurl"])
		fp.close()
		idxfile = open('log.index','w')
		idxfile.write(log_filename + " " + str(rno) + "\n")
		idxfile.flush()
		idxfile.close()	
		nfn = getnextfile(log_filename)
		if nfn == "":
			run = False
		else:
			log_filename = nfn
			log_lines = 0

	transport.close()
