#!/bin/sh

cd ../src/proxy
python feed_proxy_server.py ttserver ../../feed_set ../../regex_set > log &
