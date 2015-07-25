project (ModifiedLoG)
cmake_minimum_required (VERSION 3.1)

set(CMAKE_BUILD_TYPE Debug)

set(EXEC_NAME mlog)

set(INC_FILES
    modified_log.h
)

set(SRC_FILES
    modified_log.c
)

add_executable(${EXEC_NAME} modified_log)
