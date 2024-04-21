# TODO 关于模块引入的处理方式，下面出现了两种，一种是通过遍历，一种是直接手写，后续统一

# 遍历所有模块目录，将其头文件目录添加到 include_directories
file(GLOB MODULE_DIRS "${PROJECT_SOURCE_DIR}/src/*")
foreach(MODULE_DIR ${MODULE_DIRS})
    if(IS_DIRECTORY ${MODULE_DIR})
        include_directories(${MODULE_DIR})
    endif()
endforeach()

aux_source_directory (${CMAKE_CURRENT_SOURCE_DIR} SRC_GTEST_MATH)
add_executable (gtest_math EXCLUDE_FROM_ALL ${SRC_GTEST_MATH})
target_link_libraries (gtest_math lzx0626math lzx0626util gtest gtest_main pthread)
gtest_discover_tests (gtest_math)
