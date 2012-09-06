#!/usr/bin/env python
# -*- coding: utf-8 -*-

import httplib  

headers={
		"User-Agent": "Mozilla/5.0 (X11; Linux x86_64; rv:10.0.5) Gecko/20120606 Firefox/10.0.5",
		"Accept": "text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8",
		"Accept-Language": "en-us,en;q=0.5",
		"Accept-Encoding": "gzip, deflate",
		"Connection": "keep-alive",
		"Cookie": "do_beacon_id=220.167.54.139.1344246764447.6; CAS_LOGIN_STATE=1; sdo_dw_track=\"TTI3QK2pTN+0VDFpQkMhNQ==\""
}

conn = httplib.HTTPConnection("anquan.sdo.com")  
conn.request('get', '/views/v1/protectiframe.aspx?_1=1&theme=v2', headers=headers)  
resp = conn.getresponse()
#print resp.getheaders()  
print resp.read()  
conn.close() 
