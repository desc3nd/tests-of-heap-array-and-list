cmake_minimum_required(VERSION 3.15)
project(tests-of-heap-array-and-list)
add_compile_options(-Wall -Wextra)
set(CMAKE_CXX_STANDARD 14)


add_executable(nowy main.cpp dynamicArray.cpp dynamicArray.h List.cpp List.h bin_heap.cpp bin_heap.h BstTree.cpp BstTree.h structureTests.cpp structureTests.h stopWatch.cpp stopWatch.h TimeTests.cpp TimeTests.h menu.cpp menu.h DataGenerator.cpp DataGenerator.h outcomes.cpp outcomes.h)
set(CMAKE_EXE_LINKER_FLAGS "-static")
