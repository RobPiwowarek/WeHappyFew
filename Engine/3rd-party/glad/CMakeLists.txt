cmake_minimum_required(VERSION 3.17)
project(Glad)

include_directories(include)

add_library(glad src/glad.c)
