cmake_minimum_required(VERSION 3.15)
project(lista1)

set(CMAKE_CXX_STANDARD 14)

add_executable(lista1 main.cpp algorithms/FiniteAutomatonMatcher.cpp algorithms/FiniteAutomatonMatcher.h algorithms/Alphabet.cpp algorithms/Alphabet.h algorithms/FunctionMap.cpp algorithms/FunctionMap.h algorithms/PatternMatcher.cpp algorithms/PatternMatcher.h)