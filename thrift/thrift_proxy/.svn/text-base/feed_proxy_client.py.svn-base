import sys
sys.path.append("../src/proxy")
import feed
import ttypes
from thrift import Thrift
from thrift.transport import TSocket
from thrift.transport import TTransport
from thrift.protocol import TBinaryProtocol

address = ('10.156.24.9', 19090)
def put_default_url_list(file):
    transport = TSocket.TSocket(address[0], address[1])
    transport = TTransport.TBufferedTransport(transport)
    protocol = TBinaryProtocol.TBinaryProtocol(transport)
    client = feed.Client(protocol)
    transport.open()

    list = []
    total_count = 0
    for line in open(file):
        list.append(line[:-1])
        total_count += 1
        if len(list) >= 1000:
            transport_failed = True
            for i in range(3):
                if client.putDefaultFetchList(list):
                    transport_failed = False
                    print '%s urls are successfully uploaded' % str(total_count)
                    break
            if transport_failed:
                print 'error for upload url list to %s' % str(address)
                break
            list = []

    if len(list) > 0:
        transport_failed = True
        for i in range(3):
            if client.putDefaultFetchList(list):
                transport_failed = False
                break
        if transport_failed:
            print 'error for upload url list to %s' % str(address)
            sys.exit()
        
    print 'totally %s urls are successfully uploaded to %s' % (str(total_count), str(address))

if __name__ == '__main__':
    if len(sys.argv) < 2:
        print 'Usage: python feed_proxy_client.py url_list'
        sys.exit()
    put_default_url_list(sys.argv[1])

#link = ttypes.LinkMeta(url='http://test.com', freq=12, max_fetch='3', expire='inf', depth=4, schedule='5', method='chk', retry_num=3, blob='test')
#print client.putFetchList([link])

#link_2 = ttypes.LinkMeta(url='http://test2.com', freq=12, max_fetch='3', expire='in', depth=4, schedule='5', method='chk', retry_num=3, blob='test')
#print client.putFetchList([link, link_2])

#print client.putDefaultFetchList(['http://www.example.com', 'http://abc.com'])
