message ("-- Building on Unix ...")

# 由于我们配置了ccache，所以这里要设置为gcc和g++，这样才能用我们配置的软连接代替系统设置的，才能进入ccache
set(CMAKE_C_COMPILER "gcc")
set(CMAKE_CXX_COMPILER "g++")

message("-- Using C Compiler: ${CMAKE_C_COMPILER} (${CMAKE_C_COMPILER_VERSION})")
message("-- Using C++ Compiler: ${CMAKE_CXX_COMPILER} (${CMAKE_CXX_COMPILER_VERSION})")
