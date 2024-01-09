message(STATUS "Configuring gtest...")

# 获取 test 目录下所有子目录
file(GLOB TEST_SUBDIRS RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *)

# 遍历每个子目录
foreach(test_dir ${TEST_SUBDIRS})
    if(IS_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/${test_dir})
        # 添加当前测试目录下的所有源文件
        file(GLOB_RECURSE test_sources "${test_dir}/*.cpp")

        # 获取子目录的名称
        get_filename_component(test_name ${test_dir} NAME)

        # 生成对应的可执行文件，输出到 build/test/子目录名 目录下
        add_executable(gtest_${test_name} ${test_sources})
        set_target_properties(gtest_${test_name} PROPERTIES
                              RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/test/${test_dir})

        # 包含头文件路径，可以递归包含
        file(GLOB_RECURSE src_headers "${CMAKE_SOURCE_DIR}/src/*.h")
        list(FILTER src_headers EXCLUDE REGEX "/CMakeFiles/")

        # 移除目录，只保留头文件
        foreach(header ${src_headers})
            get_filename_component(header_path ${header} DIRECTORY)
            set(src_include_dirs ${src_include_dirs} ${header_path})
        endforeach()

        list(REMOVE_DUPLICATES src_include_dirs)

        include_directories(${src_include_dirs})

        # 遍历链接所有静态库
        file(GLOB LIBRARIES ${CMAKE_BINARY_DIR}/lib/lzx0626*.a)
        foreach(library ${LIBRARIES})
            target_link_libraries(gtest_${test_name} PRIVATE ${library})
        endforeach()

        # 链接 Google Test 和其他库
        target_link_libraries(gtest_${test_name} PRIVATE gtest gtest_main lzx0626${test_dir})

    endif()
endforeach()
