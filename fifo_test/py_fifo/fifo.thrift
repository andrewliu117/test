namespace java com.snda.fifo.thrift
namespace cpp fifo

enum ReturnCode
{
OK = 1,
INVALIDINPUT = 2,
INTERNALERROR = 3,
}

service FifoInterface
{
        ReturnCode put(1:string meta,2:string value); 
}

