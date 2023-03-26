cmake_minimum_required(VERSION 3.0.0)
project(mousemove03 VERSION 0.1.0)

include(CTest)
enable_testing()

find_package(PkgConfig REQUIRED)

pkg_check_modules(GTKMM REQUIRED gtkmm-3.0)

link_directories(
    ${GTKMM_LIBRARY_DIRS}
)

include_directories(
    ${GTKMM_INCLUDE_DIRS}
)

add_definitions(
    ${GTKMM_CFLAGS_OTHER}
)

add_executable(mousemove03 main.cpp)

target_link_libraries(
    mousemove03
    ${GTKMM_LIBRARIES}
)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
