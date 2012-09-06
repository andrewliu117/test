#!/usr/bin/env python
# -*- coding: utf-8 -*-
import sys
reload(sys)
sys.setdefaultencoding('utf8')

import os
#import sys
import time
import urllib2
import re
import hashlib
import json

if len(sys.argv) < 2:
	print "input url as a paramter"
	sys.exit()

url = sys.argv[1] 
print sys.argv[1]
#page = urllib2.urlopen(url).read().decode('gbk').encode('utf-8')
page = urllib2.urlopen(url).read()
print page
