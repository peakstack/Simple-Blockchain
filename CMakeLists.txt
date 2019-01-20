cmake_minimum_required(VERSION 3.12)
project(blockchain)

set(CMAKE_CXX_STANDARD 14)

add_executable(blockchain main.cpp blockchain.cpp blockchain.h block.cpp block.h keccak.cpp keccak.h)
