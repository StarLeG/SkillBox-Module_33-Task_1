cmake_minimum_required(VERSION 3.25.1)
project(Task_33_1)

set(Boost_INCLUDE_DIR "c:\\boost_1_81_0")
set(Boost_LIBRARY_DIR "c:\\boost_1_81_0\\stage\\lib")
find_package(Boost COMPONENTS REQUIRED)
include_directories(${Boost_INCLUDE_DIR})
link_directories(${Boost_LIBRARY_DIR})
add_subdirectory(src)
#add_library(${PROJECT_NAME})
target_link_libraries(${PROJECT_NAME} ${Boost_LIBRARIES})



