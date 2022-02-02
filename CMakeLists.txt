
cmake_minimum_required(VERSION 3.18)
project(SubsetSum)

set(CMAKE_CXX_STANDARD 20)

if (MSVC)
    # warning level 4 and all warnings as errors
    add_compile_options(/W4 /WX)
else()
    # lots of warnings and all warnings as errors
    add_compile_options(-Wall -Wextra -pedantic -Werror)
endif()

add_executable(subset_sum subset_sum.cc)

## BOOST
find_package(Boost COMPONENTS system filesystem unit_test_framework REQUIRED)
include_directories(${Boost_INCLUDE_DIRS})
add_executable(test tests.cc)
target_link_libraries(test ${Boost_LIBRARIES})
