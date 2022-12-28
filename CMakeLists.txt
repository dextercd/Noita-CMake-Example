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
