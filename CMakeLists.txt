
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


## BOOST
# find_package(Boost 1.71.0 REQUIRED system)
# include_directories(${Boost_INCLUDE_DIRS})
add_executable(subset_sum subset_sum.cc)
# target_link_libraries(subset_sum ${Boost_LIBRARIES})