cmake_minimum_required(VERSION 3.15)

project(cpp_logger LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


find_package(CURL REQUIRED)

set(CPP_LOGGER_SOURCES
    src/Logger.cpp
    src/FileSink.cpp
    src/ConsoleSink.cpp
    src/ColorFormatter.cpp
)

add_library(cpp_logger STATIC ${CPP_LOGGER_SOURCES})

add_library(cpp_logger::cpp_logger ALIAS cpp_logger)

target_include_directories(cpp_logger
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
)



target_compile_options(cpp_logger PRIVATE
    $<$<CXX_COMPILER_ID:GNU>:-Wall -Wextra -Wpedantic>
    $<$<CXX_COMPILER_ID:MSVC>:/W4>
)

target_compile_features(cpp_logger PUBLIC cxx_std_17)

target_link_libraries(cpp_logger PRIVATE CURL::libcurl)

add_executable(testLog)
target_sources(testLog PRIVATE tests/testLog.cpp)
target_link_libraries(testLog PRIVATE cpp_logger pthread)
include_directories("include/logger")