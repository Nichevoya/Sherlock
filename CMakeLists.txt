# ------------------------------ configuration ----------------------------- 

cmake_minimum_required(VERSION 3.27.7)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/.cmake/")

project("Duplicate Remover" CXX)

# ------------------------------ server steps ------------------------------ 

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    add_definitions(-DDEBUG_MODE)
elseif(CMAKE_BUILD_TYPE STREQUAL "Release")
    add_definitions(-DRELEASE_MODE)
elseif(CMAKE_BUILD_TYPE STREQUAL "Distribution")
    add_definitions(-DDIST_MODE)
endif()

# ------------------------------ configuration ----------------------------- 

if (UNIX)
    add_definitions(-DUNIX)
    set(COMPILATION_FLAGS
        -std=c++23 -fPIC 
        -Wall -Wextra -Werror -Wpedantic -g 
    )

elseif(WIN32)
    add_definitions(-DWIN32)
    set(COMPILATION_FLAGS
        /std:c++23 
        /W4 /Zi 
    )

endif()

set(INCLUDE_DIRECTORIES 
    
)

set(LIBRARY_LINK_FLAGS 
    
)

set(DUPLICATE_REMOVER_BINARY bin)

file(GLOB_RECURSE DUPLICATE_REMOVER_HEADERS "./source/*.hpp")
file(GLOB_RECURSE DUPLICATE_REMOVER_SOURCES "./source/*.cpp")

add_executable(${DUPLICATE_REMOVER_BINARY}
    ${DUPLICATE_REMOVER_HEADERS}
    ${DUPLICATE_REMOVER_SOURCES}
)

# ---------------------------- compilation flags --------------------------- 

target_compile_options(${DUPLICATE_REMOVER_BINARY} PRIVATE 
    ${COMPILATION_FLAGS}
)

# ----------------------------- link libraries ----------------------------- 

target_link_libraries(${DUPLICATE_REMOVER_BINARY} PRIVATE 
    ${LIBRARY_LINK_FLAGS}
)

# ----------------------------- header include ----------------------------- 

target_include_directories(${DUPLICATE_REMOVER_BINARY} PRIVATE 
    ${INCLUDE_DIRECTORIES}
)

# ---------------------------- target properties --------------------------- 

set_target_properties(${DUPLICATE_REMOVER_BINARY} PROPERTIES 
    LINKER_LANGUAGE CXX 
    RUNTIME_OUTPUT_NAME "duplicate remover" 
)

install(
    TARGETS ${DUPLICATE_REMOVER_BINARY} 
    DESTINATION ${CMAKE_SOURCE_DIR}
)
