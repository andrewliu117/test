#!/bin/bash
g++ -I./gtest/include foo_test.cpp ./gtest/gtest_main.a -lpthread -o foo_test.run
g++ -I./gtest/include foo_main.cpp foo_test.cpp ./gtest/libgtest.a -lpthread -o foo_main.run
g++ -I./gtest/include foo_suit.cpp ./gtest/gtest_main.a -lpthread -o foo_suit.run
g++ -I./gtest/include foo_case.cpp ./gtest/gtest_main.a -lutil -lpthread -o foo_case.run
