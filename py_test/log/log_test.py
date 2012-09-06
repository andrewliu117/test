#!/usr/bin/env python
# -*- coding: utf-8 -*-
#========================================================================
# Author: Charlse.Zhang
# Email: feiyuwgmail.com
# File Name: log_test.py
# Description: 
#   
# Edit History: 
#   2012-06-13    File created.
#========================================================================
### logging
#import logging
#import logging.config
#logging.config.fileConfig((os.path.join(os.path.dirname(__file__), '../conf/fifo_js_getter.conf')))

import logging.config  
import time
  
  
logging.config.fileConfig("log.conf")  
  
  
lhjlog = logging.getLogger('lhjExample')  
log = logging.getLogger('simpleExample')  
  
  
lhjlog.info("liuhongjiang")
log.info("log info")  
log.error("log error")  

time.sleep(130)
lhjlog.info("liuhongjiang2")
