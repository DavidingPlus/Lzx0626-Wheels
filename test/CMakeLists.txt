message(STATUS "Configuring gtest...")

enable_testing ()
find_package (GTest REQUIRED)
if (NOT GTest_FOUND)
    message (WARNING "GoogleTest is not installed...")
    return ()
endif ()
include (GoogleTest)

add_subdirectory (math)
add_subdirectory (util)

add_custom_target (tests)
add_dependencies (tests gtest_math gtest_util)

message (STATUS "Done configuring gtest...")
