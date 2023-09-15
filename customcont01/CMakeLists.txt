cmake_minimum_required(VERSION 3.0.0)

set(PROJECT_TARGET customcont01)
project(${PROJECT_TARGET}} VERSION 0.1.0 LANGUAGES CXX)

find_package(PkgConfig)
pkg_check_modules(GTKMM gtkmm-4.0)

include(CTest)
enable_testing()

set(SOURCES
    main.cpp
    MainWindow.cpp
    MyContainer.cpp
)

set(
    HEADERS
    MainWindow.h
    MyContainer.h
)

add_executable(${PROJECT_TARGET} ${SOURCES} ${HEADERS})

target_link_libraries(${PROJECT_TARGET} PRIVATE ${GTKMM_LIBRARIES})

target_include_directories(${PROJECT_TARGET} PRIVATE ${GTKMM_INCLUDE_DIRS})
target_link_directories(${PROJECT_TARGET} PRIVATE ${GTKMM_LIBRARY_DIRS})
target_compile_options(${PROJECT_TARGET} PRIVATE ${GTKMM_CFLAGS_OTHER})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})

include(CPack)
