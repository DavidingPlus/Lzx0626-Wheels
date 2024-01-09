message(STATUS "Configuring snippet...")

# 获取 snippet 目录下所有子目录
file(GLOB TEST_SUBDIRS "${CMAKE_CURRENT_SOURCE_DIR}/*")

# 遍历每个子目录
foreach(test_dir ${TEST_SUBDIRS})

    # 获取测试目录的名称
    get_filename_component(test_name ${test_dir} NAME)

    # 检查是否存在 .buildme 文件，这一步已经过滤掉了README.md，后续不需要进一步操作了
    if(EXISTS "${test_dir}/.buildme")
        # 添加当前测试目录下的所有源文件
        file(GLOB test_sources "${test_dir}/*.cpp")

        # 生成对应的可执行文件
        add_executable(${test_name} ${test_sources})

        # 设置生成的可执行文件输出路径为 build/snippet 目录下
        set_target_properties(${test_name} PROPERTIES
                              RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/snippet/${test_name})

        # 遍历每个库，保证库和头文件都能正常包含
        foreach(subdir ${SUBDIRS})

            # 获取子目录的名称（假设子目录名即为库名）
            get_filename_component(libname ${subdir} NAME)

            # 添加当前子目录下的所有源文件
            file(GLOB_RECURSE lib_sources "${subdir}/*.cpp" "${subdir}/*.h")

            # 仅在有源文件时链接静态库（因为我设置了_null.cpp，所以都是有的）
            if(lib_sources)
                # 链接静态库
                # 这里搜索静态库的名称是通过src来的而不是通过build/lib是因为顺便就把头文件包含了
                target_link_libraries(${test_name} lzx0626${libname})

                # 包含头文件路径
                target_include_directories(${test_name} PRIVATE ${CMAKE_SOURCE_DIR}/src/${libname})
            endif()

        endforeach()
    endif()

endforeach()
