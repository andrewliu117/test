#!/usr/bin/env python
# -*- coding: utf-8 -*-
import httplib  

headers={
		"User-Agent": "Mozilla/5.0 (Windows NT 5.1; rv:13.0) Gecko/20100101 Firefox/13.0.1",
		"Accept": "text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8",
		"Accept-Language": "zh-cn,zh;q=0.8,en-us;q=0.5,en;q=0.3",
		"Accept-Encoding": "gzip, deflate",
		"Connection": "keep-alive",
		"Cookie": "REG_GAEA_FROM=212; beacon_visit_count=15; allow_pt_access=1; PhoneRegType_Page=phone_default.aspx; JSESSIONID=1n3t914wzgy3zbzrfte9hxe4p; b_t_s=t142501328428xs; sdo_beacon_id=220.167.54.139.134250141486.5; SNDA_ADRefererSystem_UserTicket=1d2f8ef5-7bcf-4d39-815a-6d6b507aeac0; SNDA_ADRefererSystem_ADID=; SNDA_ADRefererSystem_RefererUrl=http%3a%2f%2fregister.sdo.com%2fgaea%2finput_pt.aspx%3ffrom%3d317%26CUSTOM_REG_SUCC_URL%3dhttp%3a%2f%2fwww.quanloo.com%2fuser%2fregister%3ff%3d%26hideos%3dtrue%26hideidname%3dtrue%26zone%3dhome_embed; SNDA_ADRefererSystem_RefererTime=2012-07-17 13:03:15; SNDA_ADRefererSystem_InSiteUrl=http%3a%2f%2fadrs.sdo.com%2fADRefererSystem%2fprereg.html; SNDA_ADRefererSystem_ClientSign=ECBF3DA21B2F0F18122F4F4DB6D22597; SNDA_ADRefererSystem_MachineTicket=1d2f8ef5-7bcf-4d39-815a-6d6b507aeac0"}

conn = httplib.HTTPConnection("register.sdo.com")  
conn.request('get', '/gaea/input_pt.aspx?from=212', headers=headers)  
print conn.getresponse().getheaders()  
#print conn.getresponse().read()  
conn.close() 
