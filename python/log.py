#!/usr/bin/env python
# -*- coding: utf-8 -*-

import json
import sys
import codecs
import locale

#fd = open("fifo_sender.video23.sii.cn.worker.log.INFO.20120509-233119.30653.bak","r")
fd = open("fifo_sender.video23.sii.cn.worker.log.INFO.20120509-233119.30653","r")

ex = 0
for line in fd:
	if line.find("INSERT") > 0:
		try:
			idx = line.find("{")
			obj = json.loads(line[idx:], enconding = "gb2312")
			print obj["playurl"]
		except:
			print line[idx:]
			ex += 1

print ex
