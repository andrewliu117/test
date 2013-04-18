#!/bin/bash
set -x
#g++ a.cpp -o a.run 
#g++ byte.cpp -o byte.run
#g++ sizeof.cpp -o sizeof.run
#g++ str.cpp -o str.run
#g++ file.cpp -o file.run
#g++ -g stack_size.cpp -o stack_size.run

for i in `ls *.cpp`
do
    name=`echo $i | cut -d"." -f1`
    g++ -g -o $name".run" $i
done
