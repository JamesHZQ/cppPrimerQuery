cmake_minimum_required(VERSION 3.14)
project(cppPrimerQuerye)

set(CMAKE_CXX_STANDARD 14)

add_executable(cppPrimerQuerye main.cpp
                                TextQuery.cpp
                                NotQuery.cpp
                                Query.cpp
                                OrQuery.cpp
                                AndQuery.cpp)