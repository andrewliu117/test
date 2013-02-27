ulimit -c  unlimited
export LD_LIBRARY_PATH=${LD_LIBRARY_PATH}:/home/yaolu/install/log4cxx/lib/
nohup ./thrift_fifo 1> log 2> err &
