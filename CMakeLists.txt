cmake_minimum_required(VERSION 3.31)
project(DStests)

set(CMAKE_CXX_STANDARD 23)

add_executable(DStests main.cpp
        sorting.cpp
        tree.cpp
        arraybasedlist.h
        stack.h
        myqueue.h
        queuebutcircular.h
)
