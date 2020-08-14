cmake_minimum_required(VERSION 3.1)

if (NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
    message("Setting build type to 'RelWithDebinfo' as none was specified.")
    set(CMAKE_BUILD_TYPE RelWithDebInfo CACHE STRING "Choose the type of build." FORCE)
    set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS "Debug" "Release" "MinSizeRel" "Release" "MinSizeRel" "RelWithDebInfo")
endif()

project (vmatch)

set(SOURCES
    src/vmain.c
    src/parser/parse_wav.c
)

add_executable(${PROJECT_NAME} ${SOURCES})

target_include_directories(vmatch
    PRIVATE
        ${PROJECT_SOURCE_DIR}/parser
)