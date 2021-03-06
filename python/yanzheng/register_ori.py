#!/usr/bin/env python
# -*- coding: utf-8 -*-
import httplib  
import urllib2
import HTMLParser
import urlparse

urlString = "http://register.sdo.com/gaea/input_pt.aspx?from=212"

#把图像文件保存至硬盘
def getImage(addr):
    u = urllib2.urlopen(addr)
    data = u.read()
    splitPath = addr.split('/')
    fName = splitPath.pop()
    if fName.find('.')+4 == len(fName):
        print "Saving %s" % fName
        f = open(fName, 'wb')
        f.write(data)
        f.close()


#定义HTML解析器
class parseImages(HTMLParser.HTMLParser):
    def handle_starttag(self, tag, attrs):
        if tag == 'img':
            for name,value in attrs:
                if name == 'src':
                    print value
                    getImage(urlString + value)

headers={
            "User-Agent": "Mozilla/5.0 (Windows NT 5.1; rv:13.0) Gecko/20100101 Firefox/13.0.1",
	    "Accept": "text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8",
	    "Accept-Language": "zh-cn,zh;q=0.8,en-us;q=0.5,en;q=0.3",
	    "Accept-Encoding": "gzip, deflate",
	    "Connection": "keep-alive",
	    "Cookie": "REG_GAEA_FROM=212; beacon_visit_count=15; allow_pt_access=1; PhoneRegType_Page=phone_default.aspx; JSESSIONID=1n3t914wzgy3zbzrfte9hxe4p; b_t_s=t142501328428xs; sdo_beacon_id=220.167.54.139.134250141486.5; SNDA_ADRefererSystem_UserTicket=1d2f8ef5-7bcf-4d39-815a-6d6b507aeac0; SNDA_ADRefererSystem_ADID=; SNDA_ADRefererSystem_RefererUrl=http%3a%2f%2fregister.sdo.com%2fgaea%2finput_pt.aspx%3ffrom%3d317%26CUSTOM_REG_SUCC_URL%3dhttp%3a%2f%2fwww.quanloo.com%2fuser%2fregister%3ff%3d%26hideos%3dtrue%26hideidname%3dtrue%26zone%3dhome_embed; SNDA_ADRefererSystem_RefererTime=2012-07-17 13:03:15; SNDA_ADRefererSystem_InSiteUrl=http%3a%2f%2fadrs.sdo.com%2fADRefererSystem%2fprereg.html; SNDA_ADRefererSystem_ClientSign=ECBF3DA21B2F0F18122F4F4DB6D22597; SNDA_ADRefererSystem_MachineTicket=1d2f8ef5-7bcf-4d39-815a-6d6b507aeac0"}

conn = httplib.HTTPConnection("register.sdo.com")  
conn_info = conn.request('get', '/gaea/input_pt.aspx?from=212', headers=headers)  
response_info=conn.getresponse()

f=open("txt.html","w")
f.write(response_info.read())
f.close()

#获取响应头信息
str1 = httplib.HTTPResponse.getheaders(response_info)
conn.close()

str1 = str(str1[4])
seesion_ID = str1[str1.find('JSESSIONID'):str1.find(';Path')]
headers1 = {
            "User-Agent":"Mozilla/5.0 (Windows NT 5.1; rv:13.0) Gecko/20100101 Firefox/13.0.1",
            "Accept": "image/png,image/*;q=0.8,*/*;q=0.5",
            "Accept-Language": "zh-cn,zh;q=0.8,en-us;q=0.5,en;q=0.3",
            "Accept-Encoding": "gzip, deflate",
            "Connection": "keep-alive",
            "Referer": "http://register.sdo.com/gaea/input_pt.aspx?from=212",
            "Cookie":"CaptchaSeq=eXSgMCIkkyNgGaSs; sdo_beacon_id=220.167.54.139.1342501884988.5; SNDA_ADRefererSystem_MachineTicket=ae3cc75a-fc74-463f-b829-87dc2461f7f7; SNDA_ADRefererSystem_UserTicket=d4bbaf7f-a0fe-4681-b27c-c3e62b3ac615; SNDA_ADRefererSystem_ADID=; SNDA_ADRefererSystem_RefererUrl=(DIRECT); SNDA_ADRefererSystem_RefererTime=2012-07-18 10:25:25; SNDA_ADRefererSystem_InSiteUrl=http%3a%2f%2fadrs.sdo.com%2fADRefererSystem%2fprereg.html; SNDA_ADRefererSystem_ClientSign=BEC0C6974187D91D7314F091AE22F31A; aa_ad_gid=220.167.54.139.1342578696667.6"}

conn1 = httplib.HTTPConnection("captcha.sdo.com")
conn1.request('get', '/fcgi-bin/show_img.fcgi?appid=112&gamehttp://captcha.sdo.com/fcgi-bin/show_img.fcgi?appid=112&gameid=212&areaid=0&session_key=3fhubOrOE2hZ5DD5&image_type=0&rand=0.9326562678906674id=212&areaid=0&session_key=3fhubOrOE2hZ5DD5&image_type=0&rand=0.9326562678906674', headers=headers1)
response_info1=conn1.getresponse()
str1 = httplib.HTTPResponse.getheaders(response_info)

f=open("test.jpg","w")
f.write(response_info1.read())
f.close()


#创建HTML解析器的实例
lParser = parseImages()

#打开HTML文件
u = urllib2.urlopen("http://captcha.sdo.com/fcgi-bin/show_img.fcgi?appid=112&gamehttp://captcha.sdo.com/fcgi-bin/show_img.fcgi?appid=112&gameid=212&areaid=0&session_key=3fhubOrOE2hZ5DD5&image_type=0&rand=0.9326562678906674id=212&areaid=0&session_key=3fhubOrOE2hZ5DD5&image_type=0&rand=0.9326562678906674")
lParser.feed(u.read())

