#!/usr/bin/env python
# -*- coding: utf-8 -*-  
import MyCppModule  
#导入python的模块（也就是c的模块，注意so文件名是MyCppModule    
r = MyCppModule.MyCppFun1("yes",2,"no")  
print r   
MyCppModule.set(2)  
MyCppModule.aprint()  
print "OK" 
