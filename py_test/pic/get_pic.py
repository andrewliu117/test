#!/usr/bin/env python
# -*- coding: utf-8 -*-
import httplib

headers = {
		"User-Agent": "Mozilla/5.0 (Windows NT 5.1; rv:13.0) Gecko/20100101 Firefox/13.0.1",
		"Accept": "text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8",
		"Accept-Language": "zh-cn,zh;q=0.8,en-us;q=0.5,en;q=0.3",
		"Accept-Encoding": "gzip, deflate",
		"Connection": "keep-alive",
		"Cookie": "CaptchaSeq=mf1kVy6gH9Afviau; sdo_beacon_id=220.167.54.139.134250141486.5; SNDA_ADRefererSystem_MachineTicket=1d2f8ef5-7bcf-4d39-815a-6d6b507aeac0; CAS_LOGIN_STATE=1; sdo_dw_track=\"TTI3QK2pTN+0VDFpQkMhNQ==\""}

conn = httplib.HTTPConnection("captcha.sdo.com")  
conn.request('get', '/fcgi-bin/show_img.fcgi?appid=112&gameid=212&areaid=0&session_key=5hYkLxHZk2hWi4kK&image_type=0&rand=0.05149567786695608', headers=headers)  
res = conn.getresponse();
print 'headers:', res.getheaders()  
f = open("t.jpg", "w")
f.write(res.read())
conn.close() 
