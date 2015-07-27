project (ModifiedLoG)
cmake_minimum_required (VERSION 3.1)

set(CMAKE_BUILD_TYPE Debug)

set(EXEC_NAME mlog)

set(INC_FILES
    image.h
    modified_log.h
)

set(SRC_FILES
    image.c
    modified_log.c
)

add_library(convolve_tools SHARED ${INCLUDE_FILES} ${SRC_FILES})
