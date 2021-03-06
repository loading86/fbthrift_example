cmake_minimum_required(VERSION 3.0.0)
project(fbthrift_ex CXX)

set(CMAKE_CXX_COMPILER g++)

macro(remove_cxx_flag flag)
    string(REPLACE "${flag}" "" CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE}")
endmacro()

option(USE_O2 "Use -O2 instead of the default -O3" OFF)

set(THREADS_PREFER_PTHREAD_FLAG ON)
set(PATH_TO_FBTHRIFT /fbthrift)
set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

FILE(GLOB FBGEN "./gen-cpp2/*.cpp")
add_executable(fbthrift_ex
    main.cc	
    ${FBGEN}
)

find_package(FBThrift REQUIRED)
find_package(Folly REQUIRED)
find_package(Wangle REQUIRED)
find_package(fizz REQUIRED)
find_package(Threads REQUIRED)
find_package(yarpl REQUIRED)
find_package(rsocket REQUIRED)
find_package(Glog)
find_package(Gflags)

target_include_directories(fbthrift_ex PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(fbthrift_ex PUBLIC
    FBThrift::thriftcpp2
)

# generate thrift files
#add_custom_target(thrift)
#add_custom_command(
#	TARGET thrift
#	COMMAND thrift1 --gen mstch_cpp2 -o ../ --templates ${PATH_TO_FBTHRIFT}/thrift/compiler/generate/templates  ../example.thrift)
