cmake_minimum_required(VERSION 3.25.1)
file(GLOB
        CPP_SOURCES "*.cpp")

add_executable(${PROJECT_NAME} ${CPP_SOURCES}
                               ${MY_INCLUDE_DIR}/base.h
                               ${MY_INCLUDE_DIR}/menu.h)

target_include_directories(${PROJECT_NAME} PUBLIC ${MY_INCLUDE_DIR})
