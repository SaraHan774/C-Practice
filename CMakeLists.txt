cmake_minimum_required(VERSION 3.15)
project(cplus_hyu)

set(CMAKE_CXX_STANDARD 14)

add_executable(cplus_hyu virtual.cpp)
add_executable(assignment4 assignment4_2.cpp assignment4_1.cpp Lecture1126_2.cpp Lecture1126_3.cpp)
add_executable(examples alg7_11.cpp)

add_executable(exceptions exceptions.cpp)
add_executable(dbms prime_mt.cpp)

add_executable(Lecture1126 Lecture1126.cpp Lecture1126_2.cpp Lecture1126_3.cpp)

add_executable(assignment5 assignment5.cpp)

add_executable(main main.cpp Account.cpp Account.h Circle.cpp Circle.h Date.cpp Date.h Histogram.cpp Histogram.h Random.cpp Random.h Rectangle.cpp Tower.cpp Tower.h)
add_executable(solution3 solution3.cpp)
add_executable(solution4 solution4.cpp)
add_executable(solution5 solution5.cpp)

add_executable(callbyvalue callbyvalue.cpp)

add_executable(final_main final_main.cpp)
add_executable(protected protected.cpp)
add_executable(dynamicalloc dynamicalloc.cpp)

add_executable(practicals_ practicals/MainPrac.cpp)

add_executable(overloading overloading.cpp)