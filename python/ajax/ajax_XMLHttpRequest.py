#!/usr/bin/env python
# -*- coding: utf-8 -*-


#http://outofmemory.cn/code-snippet/1885/python-moni-ajax-request-get-ajax-request-response
#http://zhouxi2010.iteye.com/blog/1474006

import json
import urllib2
import time
import sys

headers={
"Host": "pic.hao123.com",
"User-Agent": "Mozilla/5.0 (X11; Ubuntu; Linux x86_64; rv:18.0) Gecko/20100101 Firefox/18.0",
"Accept": "application/json, text/javascript, */*; q=0.01",
"Accept-Language": "en-US,en;q=0.5",
"Accept-Encoding": "gzip, deflate",
"X-Requested-With": "XMLHttpRequest",
"Referer": "http://pic.hao123.com/meinv?style=xl",
"Cookie": "BAIDUID=734D1B24D77B0C86D9F1BAC484365D16:FG=1; LAT=1361089555317; FLASHID=734D1B24D77B0C86D9F1BAC484365D16:FG=1; loc2=1%7C%E6%B2%B3%E5%8D%97%7C%E6%BF%AE%E9%98%B3; static=1; Hm_lvt_f0a0dcac6f8ae87519c0c94b99788272=1361089559,1361091176; bdshare_firstime=1361089560256; Hm_lpvt_f0a0dcac6f8ae87519c0c94b99788272=1361091274",
"Connection": "keep-alive"
}

url = "http://pic.hao123.com/screen/meinv/3?v=" + str(int(time.time())) + "010&act=type"

req = urllib2.Request(url)

for k in headers.keys():
    req.add_header(k,headers[k])

response = urllib2.urlopen(req, "")
res_json = response.read()
#print res_json

pics = json.loads(res_json)
#print json.dumps(pics[0], indent=4)
#sys.exit(0)

ret = []

for item in pics:
    one_pic = {}
    item_310 = item["picurl"]["310"]
    one_pic["url"] = item_310["picurl"] 
    one_pic["image"] = item_310["picurl"]
    one_pic["preview"] = item_310["picurl"]
    one_pic["id"] = item["id"]
    one_pic["title"] = item["title"]
    one_pic["referer"] = "http://pic.hao123.com/meinv_meitui?style=xl"
    one_pic["width"] = item_310["width"]
    one_pic["height"] = item_310["height"]

    ret.append(one_pic)
    
    print json.dumps(ret, indent=4)
    
    sys.exit(0)


