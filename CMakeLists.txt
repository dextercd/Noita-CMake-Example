cmake_minimum_required(VERSION 3.24)

project(HelloMod
    VERSION 0.1.0
    DESCRIPTION "Noita example mod"
    HOMEPAGE_URL "https://github.com/dextercd/Noita-CMake-Example"
    LANGUAGES CXX
)

install(DIRECTORY HelloMod
    DESTINATION .
    COMPONENT HelloMod
)


# Dependencies

include(FetchContent)

FetchContent_Declare(EZWand
    URL https://github.com/TheHorscht/EZWand/releases/download/v1.5.0/EZWand.lua
    DOWNLOAD_NO_EXTRACT TRUE
)
FetchContent_MakeAvailable(EZWand)

install(FILES ${ezwand_SOURCE_DIR}/EZWand.lua
    DESTINATION HelloMod/lib/EZWand
    COMPONENT HelloMod
)

FetchContent_Declare(LuaJIT-MinHook
    URL https://github.com/dextercd/LuaJIT-MinHook/releases/download/release-1.1.1/LuaJIT-MinHook-1.1.1.zip
)
FetchContent_MakeAvailable(LuaJIT-MinHook)

install(DIRECTORY ${luajit-minhook_SOURCE_DIR}/
    DESTINATION HelloMod/lib/MinHook
    COMPONENT HelloMod
)


# C++ module

add_library(clipboard MODULE
    clipboard.cpp
)

install(TARGETS clipboard
    LIBRARY DESTINATION HelloMod/dll
    COMPONENT HelloMod
)


# Packaging

set(CPACK_VERBATIM_VARIABLES TRUE)
set(CPACK_GENERATOR ZIP)
set(CPACK_INCLUDE_TOPLEVEL_DIRECTORY FALSE)
set(CPACK_PACKAGE_FILE_NAME "${PROJECT_NAME}-${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}.${PROJECT_VERSION_PATCH}")
include(CPack)
