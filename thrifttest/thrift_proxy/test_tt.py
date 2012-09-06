import sys
sys.path.append('../../include')
import pytyrant
t = pytyrant.PyTyrant.open('127.0.0.1', 1978)

print len(t)
