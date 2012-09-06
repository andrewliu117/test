import os, sys
import time
import feed
from ttypes import LinkMeta

from thrift.transport import TSocket
from thrift.transport import TTransport
from thrift.protocol import TBinaryProtocol
from thrift.server import TServer

sys.path.append('../../include')
import pytyrant

class FeedProxyHandler():
    method_list = ['get', 'chk', 'GET', 'CHK'] 
    def __init__(self, mode, feed_set_path, regex_set_path):
        (self.mode, self.feed_set_path, self.regex_set_path) = (mode, feed_set_path, regex_set_path)

    def putFetchList(self, url_list):
        if len(url_list) == 0:
            return True
        return self.save(url_list)
    
    def putDefaultFetchList(self, url_list):
        if len(url_list) == 0:
            return True
        return self.save([LinkMeta(url=url, freq=10, max_fetch=1, expire=86400, depth=0, schedule=5, method='get', retry_num=3, blob='') for url in url_list])

    def addOutlinkFilter(self, reg_expr_list):
        latest_version = self.get_latest_version(self.regex_set_path)
        with open(self.regex_set_path+'/regex.'+latest_version, 'w') as f:
            for regex in reg_expr_list:
                f.write(regex+'\n')
        return True

    def cleanOutlinkFilter(self):
        return False

    def save(self, link_meta_list):
        if self.mode == 'ttserver':
            return self.write_ttserver(link_meta_list)
        else:
            return self.write_local_file(link_meta_list)

    def write_ttserver(self, link_meta_list):
        t = pytyrant.PyTyrant.open('127.0.0.1', 19091)
        for link in link_meta_list:
            (url, freq, max_fetch, expire, depth, method, schedule, retry, blob) = (link.url, link.freq, link.max_fetch, link.expire, link.depth, link.schedule, link.method, link.retry_num, link.blob)
            if len(url) == 0:
                continue
            if freq < 5:
                freq = 5
            if max_fetch != 'inf':
                try:
                   int(max_fetch)
                except:
                    continue
            if expire != 'inf':
                try:
                    int(expire)
                except:
                    continue
            if depth > 10:
                depth = 10
            if method not in self.method_list:
                methond = 'get'
            if retry > 10:
                retry = 10
            if len(blob) > 1024:
                blob = ''
            t[str(time.time())+url] = ("%s %s %s %s %s %s %s %s %s" % (url, str(freq), max_fetch, expire, str(depth), method, schedule, str(retry), blob))
        return True

    def get_latest_version(self, path):
        latest_version = 0
        file_list = os.listdir(path)
        for file in file_list:
            pos = file.rfind(".")
            if pos == -1:
                continue
            try:
                version = int(file[pos+1:])
            except:
                continue

            if version > latest_version:
                latest_version = version

        latest_version += 1
        return str(latest_version)

    def write_local_file(self, link_meta_list):
        latest_version = self.get_latest_version(self.feed_set_path)
        with open(self.feed_set_path+'/feed_set.'+latest_version, "w") as f:        
            for link in link_meta_list:
                (url, freq, max_fetch, expire, depth, method, schedule, retry, blob) = (link.url, link.freq, link.max_fetch, link.expire, link.depth, link.schedule, link.method, link.retry_num, link.blob)
                if len(url) == 0:
                    continue
                if freq < 5:
                    freq = 5
                if max_fetch != 'inf':
                    try:
                        int(max_fetch)
                    except:
                        continue
                if expire != 'inf':
                    try:
                        int(expire)
                    except:
                        continue
                if depth > 10:
                    depth = 10
                if method not in self.method_list:
                    methond = 'get'
                if retry > 10:
                    retry = 10
                if len(blob) > 1024:
                    blob = ''
                f.write("%s %s %s %s %s %s %s %s %s\n" % (url, str(freq), max_fetch, expire, str(depth), method, schedule, str(retry), blob))
        return True
        
def main():
    handler = FeedProxyHandler(sys.argv[1], sys.argv[2], sys.argv[3])
    processor = feed.Processor(handler)
    transport = TSocket.TServerSocket('0.0.0.0',19090)
    tfactory = TTransport.TBufferedTransportFactory()
    pfactory = TBinaryProtocol.TBinaryProtocolFactory()

    server = TServer.TThreadPoolServer(processor, transport, tfactory, pfactory)
    print 'Starting the server....'
    try:
        server.serve()
    except KeyboardInterrupt:
        print 'keyboard interrupted'
        sys.exit()

if __name__ == '__main__':
    if len(sys.argv) < 4:
        print 'Usage: python feed_proxy_server.py mode feed_set_path regex_set_path'
        sys.exit()

    main()
