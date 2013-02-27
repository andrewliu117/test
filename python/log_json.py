#!/usr/bin/env python
# -*- coding: utf-8 -*-

import json
import sys
import codecs
import locale

#fd = open("fifo_sender.video23.sii.cn.worker.log.INFO.20120509-233119.30653.bak","r")
fd = open("fifo_sender.video23.sii.cn.worker.log.INFO.20120509-233119.30653","r")

reader = codecs.getreader(locale.getpreferredencoding())(fd)

line = reader.readline()
ex = 0
while line:
	if line.find("INSERT") > 0:
		try:
			idx = line.find("{")
			obj = json.loads(line[idx:])
			print obj["playurl"]
		except:
			print line[idx:]
			sys.exit()
	#line = reader.readline()
	try:
		line = reader.readline()
	except:
		print line
		line = reader.readline()
		ex += 1

print ex
