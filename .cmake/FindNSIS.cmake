if (NOT NSIS_FOUND)
    include(FetchContent)

    set(NSIS_VERSION "3.09")
    set(NSIS_SHA256 F5DC52EEF1F3884230520199BAC6F36B82D643D86B003CE51BD24B05C6BA7C91)
    
    FetchContent_Declare(
        NSIS 
        URL https://prdownloads.sourceforge.net/nsis/nsis-${NSIS_VERSION}.zip
        URL_HASH SHA256=${NSIS_SHA256} 
    )
    
    FetchContent_GetProperties(NSIS)
    FetchContent_MakeAvailable(NSIS)
    
    set(CPACK_NSIS_EXECUTABLE  ${CMAKE_BINARY_DIR}/_deps/nsis-src/bin/makensis CACHE INTERNAL "") 
endif()
