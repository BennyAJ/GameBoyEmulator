cmake_minimum_required(VERSION 3.18)

project(gameboy_emulator)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED)

include_directories(include)

# Use globbing to find source files.
# Any source files added to include/ or src/ will automatically be added to the project.
file(GLOB_RECURSE INCLUDE_FILES ${CMAKE_SOURCE_DIR}/include/*.h)
file(GLOB_RECURSE SOURCE_FILES_NO_MAIN ${CMAKE_SOURCE_DIR}/src/*.cpp)
list(REMOVE_ITEM SOURCE_FILES_NO_MAIN ${CMAKE_SOURCE_DIR}/src/main.cpp)
set(SOURCE_FILES ${SOURCE_FILES_NO_MAIN} ${CMAKE_SOURCE_DIR}/src/main.cpp)

find_program(CLANG_TIDY NAMES clang-tidy clang-tidy-6.0)
if (CLANG_TIDY)
    add_custom_target(
            clang-tidy
            COMMAND ${CLANG_TIDY}
            ${SOURCE_FILES}
            --
            -std=c++20
            -I ${CMAKE_SOURCE_DIR}/include
    )
endif ()

option(ADDRESS_SANITIZER "Enable AddressSanitizer" ON)
if (ADDRESS_SANITIZER)
    message(STATUS "AddressSanitizer enabled")
    set(CMAKE_CXX_FLAGS
        "${CMAKE_CXX_FLAGS} -O1 -fno-omit-frame-pointer -fsanitize=address")
endif ()

option(UNDEFINED_SANITIZER "Enable UndefinedBehaviorSanitizer" ON)
if (UNDEFINED_SANITIZER)
    message(STATUS "UndefinedBehaviorSanitizer enabled")
    set(CMAKE_CXX_FLAGS
        "${CMAKE_CXX_FLAGS} -fsanitize=undefined -fsanitize=integer-divide-by-zero -fsanitize=shift")
endif ()

option(SLOW_SANITIZERS "Enable SlowSanitizers" ON)
if (SLOW_SANITIZERS)
    message(STATUS "SlowSanitizers enabled")
    set(CMAKE_CXX_FLAGS
        "${CMAKE_CXX_FLAGS} -fsanitize=null -fsanitize=return -fsanitize=signed-integer-overflow")
endif ()

# Turn on all of the warnings
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")

add_executable(emulator ${INCLUDE_FILES} ${SOURCE_FILES_NO_MAIN} ${SOURCE_FILES})
