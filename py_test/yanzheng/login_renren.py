#encoding = utf-8
import re   
import urllib   
import urllib2   
import cookielib   
import datetime  
import time  
from urllib2 import URLError,HTTPError  
#第一个参数为日志文件，第二个参数为用户名，第三个参数为密码  
def renren_login(logfile,username,password):  
    logfile.write(str(datetime.datetime.now()) + ' renren/r/n')  
    cj = cookielib.CookieJar()  
    post_data = urllib.urlencode(  
        {'email':username,  
         'password':password,  
        }  
        )  
    path = 'http://www.renren.com/PLogin.do'  
    opener = urllib2.build_opener(urllib2.HTTPCookieProcessor(cj))  
    urllib2.install_opener(opener)  
    req = urllib2.Request(path,post_data)  
      
    try:  
        conn = urllib2.urlopen(req)  
    except URLError,e:  
        print 'URLError'  
        logfile.write('URLError:' + str(e.code) + '/r/n')   #http://www.renren.com/SysHome.do  
        return False  
    except HTTPError,e:      
        logfile.write('HTTP Error:'+e.reason + '/r/n')  
        return False  
    if conn.geturl() == 'http://www.renren.com/201371864':           
        print 'success'  
        logfile.write('Task finished/r/n')
        return conn.read()  
    else:      
        print 'Task Failed'  
        logfile.write('Task failed/r/n')
        
# 登录成功，返回整个页面的代码

str1 = urllib2.urlopen('http://www.renren.com/PLogin.do' )
print str1.read()

file_object  = open("log.txt",'w')          
login_index = renren_login(file_object,'13980479864','maomaozhu')
file_object.close()

