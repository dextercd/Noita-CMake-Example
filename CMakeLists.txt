cmake_minimum_required(VERSION 3.24)

project(HelloMod
    VERSION 0.1.0
    DESCRIPTION "Noita example mod"
    HOMEPAGE_URL "https://github.com/dextercd/Noita-CMake-Example"
    LANGUAGES # Empty
)

install(DIRECTORY HelloMod
    DESTINATION .
    COMPONENT HelloMod
)


# Packaging

set(CPACK_VERBATIM_VARIABLES TRUE)
set(CPACK_GENERATOR ZIP)
set(CPACK_INCLUDE_TOPLEVEL_DIRECTORY FALSE)
set(CPACK_PACKAGE_FILE_NAME "${PROJECT_NAME}-${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}.${PROJECT_VERSION_PATCH}")
include(CPack)
