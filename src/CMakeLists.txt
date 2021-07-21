cmake_minimum_required(VERSION 3.0.0)

set(SOURCES main.cpp track.cpp ${MY_INCLUDE_DIR}/track.h)

add_executable(Player ${SOURCES})

target_include_directories(Player PUBLIC ${MY_INCLUDE_DIR})