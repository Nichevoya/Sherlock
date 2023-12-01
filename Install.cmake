# --------------------------------- install -------------------------------- 

install(
    TARGETS ${PROJECT_BINARY} 
    DESTINATION "./"
)

# ---------------------------------- cpack --------------------------------- 

set(CPACK_GENERATOR NSIS)

set(CPACK_PACKAGE_NAME ${PROJECT_NAME})
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "${PROJECT_NAME} - Recursively search and remove files duplicate in the current directory and subdirectories")

set(CPACK_PACKAGE_VERSION "1.0.0")
set(CPACK_PACKAGE_VERSION_MAJOR "1")
set(CPACK_PACKAGE_VERSION_MINOR "0")
set(CPACK_PACKAGE_VERSION_PATCH "0")

set(CPACK_PACKAGE_INSTALL_DIRECTORY ${PROJECT_NAME})

set(CPACK_PACKAGE_VENDOR "Helvegen")
SET(CPACK_NSIS_MODIFY_PATH ON)

include(CPack)
