# -------------------------------- sherlock -------------------------------- 

cmake_minimum_required(VERSION 3.27.7)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/.cmake/")

project("Sherlock" CXX)

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    add_definitions(-DDEBUG_MODE)
elseif(CMAKE_BUILD_TYPE STREQUAL "Release")
    add_definitions(-DRELEASE_MODE)
endif()

# ------------------------------ dependencies ------------------------------ 

if (WIN32)
    find_package(NSIS REQUIRED)
endif()

# ------------------------------ configuration ----------------------------- 

if (UNIX)
    add_definitions(-DUNIX)
    set(COMPILATION_FLAGS
        -std=c++20 -fPIC 
        -Wall -Wextra -Werror -Wpedantic -g 
    )

elseif(WIN32)
    add_definitions(-DWIN32)
    set(COMPILATION_FLAGS
        /std:c++20 
        /W4 /Zi 
    )

endif()

set(INCLUDE_DIRECTORIES 
    
)

set(LIBRARY_LINK_FLAGS 
    
)

set(PROJECT_BINARY ${PROJECT_NAME})
set(PROJECT_ICON "${CMAKE_SOURCE_DIR}/icon/icon.rc")

file(GLOB_RECURSE PROJECT_HEADERS "./source/*.hpp")
file(GLOB_RECURSE PROJECT_SOURCES "./source/*.cpp")

add_executable(${PROJECT_BINARY}
    ${PROJECT_HEADERS}
    ${PROJECT_SOURCES}
    ${PROJECT_ICON}
)

# ---------------------------- compilation flags --------------------------- 

target_compile_options(${PROJECT_BINARY} PRIVATE 
    ${COMPILATION_FLAGS}
)

# ----------------------------- link libraries ----------------------------- 

target_link_libraries(${PROJECT_BINARY} PRIVATE 
    ${LIBRARY_LINK_FLAGS}
)

# ----------------------------- header include ----------------------------- 

target_include_directories(${PROJECT_BINARY} PRIVATE 
    ${INCLUDE_DIRECTORIES}
)

# ---------------------------- target properties --------------------------- 

set_target_properties(${PROJECT_BINARY} PROPERTIES 
    LINKER_LANGUAGE CXX 
    RUNTIME_OUTPUT_NAME "Sherlock" 
)

# ------------------------------ installation ------------------------------ 

include(install.cmake)
