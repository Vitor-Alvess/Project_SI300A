cmake_minimum_required(VERSION 3.10)
project(SeriesCatalog)

include_directories(
    /usr/include/mariadb
    ${CMAKE_SOURCE_DIR}/include/controller
    ${CMAKE_SOURCE_DIR}/include/model
    ${CMAKE_SOURCE_DIR}/include/view
    ${CMAKE_SOURCE_DIR}/include/config
)

link_directories(
    /usr/local/lib/mariadb
    /usr/lib/x86_64-linux-gnu
)

file(
    GLOB_RECURSE SOURCES
    ${CMAKE_SOURCE_DIR}/src/*/*.cpp
    ${CMAKE_SOURCE_DIR}/src/*.cpp
)

add_executable(main ${SOURCES})

target_link_libraries(main
    mariadbcpp
    mariadb
)