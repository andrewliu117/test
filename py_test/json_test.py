#!/usr/bin/python
# -*- coding: utf-8 -*-
#========================================================================
# Author: Charlse.Zhang
# Email: feiyuwgmail.com
# File Name: json.py
# Description: 
#   
# Edit History: 
#   2012-05-28    File created.
#========================================================================

import json
a = {'key':'中文'}
print a['key']



jstr = '{"b":"哈"}'

json_class = json.JSONDecoder()
ja = json_class.raw_decode(jstr)
print ja

jb = json_class.decode(jstr)
print jb

jc = json.loads(jstr)
print jc

a = json.dumps(jc,ensure_ascii=False)
print a
