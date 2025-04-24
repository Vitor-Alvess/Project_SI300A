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

set(SOURCES
    src/main.cpp
    src/controller/controller.cpp
    src/model/creditsAndHelp.cpp
    src/model/menu.cpp
    src/model/register.cpp
    src/view/registerMemDAO.cpp
    src/view/registerServerDAO.cpp
    src/config/memoryDBConnection.cpp
    src/config/serverDBConnection.cpp
    src/config/utils.cpp
)

add_executable(main ${SOURCES})

target_link_libraries(main
    mariadbcpp
    mariadb
)