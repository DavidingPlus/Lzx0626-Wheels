# 设置CMake最低版本
cmake_minimum_required(VERSION 3.12)

# 设置项目名称
project(MyProject)

# 设置 C++ 标准
set(CMAKE_CXX_STANDARD 20)

# 设置编译器（跨平台），并引入 Ccache
if(CMAKE_HOST_WIN32)
    include(config-win32.cmake)

elseif(CMAKE_HOST_UNIX)
    include(config-unix.cmake)

else ()
    message (FATAL_ERROR "Unknown platform.")

endif ()

# 内存消毒器，main版本的分支用来发布，不需要添加
# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address -fno-omit-frame-pointer")

# 设置CMake_Build_Type，都用Debug好了
set(CMAKE_BUILD_TYPE Debug)

# TODO 现在的 CMakeLists 非常冗杂和难看，后续改造
# -------------------src目录静态库构建，每个分支都必须启用--------------------
# 不隔离开来是因为不想在build下面生成src目录，而是直接生成lib目录
message(STATUS "Configure generating static library into lib...")

# 获取 src 目录下所有子目录
file(GLOB SUBDIRS "src/*")

# 遍历每个子目录
foreach(subdir ${SUBDIRS})

    # 获取子目录的名称（假设子目录名即为库名）
    get_filename_component(libname ${subdir} NAME)

    # 添加当前子目录下的所有源文件
    file(GLOB_RECURSE lib_sources "${subdir}/*.cpp" "${subdir}/*.h")

    # 过滤掉 README.md 文件
    list(FILTER lib_sources EXCLUDE REGEX "/README\\.md$")

    # 仅在有源文件时生成对应的静态库
    if(lib_sources)
        # 生成对应的静态库
        add_library(lzx0626${libname} STATIC ${lib_sources})

        # 设置生成的静态库输出路径为 lib 目录下
        set_target_properties(lzx0626${libname} PROPERTIES
                              ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

        # -------------------编写sudo make install命令，方便后续安装-------------------

        # 安装头文件到 /usr/include/lzx0626/${libname} 目录
        install(DIRECTORY ${subdir}/
                DESTINATION /usr/include/lzx0626/${libname}
                FILES_MATCHING PATTERN "*.h")

        # 安装静态库到 /lib64 目录
        install(TARGETS lzx0626${libname}
                ARCHIVE DESTINATION /lib64)
    endif()

endforeach()

# -------------------snippet测试目录构建，dev分支启用，main分支不启用--------------------
message(STATUS "Snippet is not enabled...")
# add_subdirectory(snippet)

# -------------------unit test测试目录构建，dev分支启用，main分支不启用--------------------
option(ENABLE_GTEST "enable unit test" OFF)

if(ENABLE_GTEST)
    message(STATUS "Unit test is enabled...")
    add_subdirectory(test)

else()
    message(STATUS "Unit test is not enabled...")
    
endif()
