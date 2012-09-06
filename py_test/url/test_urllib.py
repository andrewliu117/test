#!/usr/bin/env python

#!/usr/bin/env python
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

url = "http://www.tudou.com/programs/view/BcXtwUMfG1I/"
page = urllib2.urlopen(url).read().decode('gbk').encode('utf-8')
file_name = "BcXtwUMfG1I.js"
fout = open(file_name, "w")
fout.write(page)
fout.close()
