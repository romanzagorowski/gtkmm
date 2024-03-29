cmake_minimum_required(VERSION 3.0.0)
project(screen03 VERSION 0.1.0)

include(CTest)
enable_testing()

find_package(PkgConfig REQUIRED)

pkg_check_modules(GTKMM REQUIRED gtkmm-3.0)

find_package(Boost 1.74 COMPONENTS filesystem REQUIRED)

link_directories(
    ${GTKMM_LIBRARY_DIRS}
    ${Boost_LIBRARY_DIRS}
)

include_directories(
    ${GTKMM_INCLUDE_DIRS}
    ${Boost_INCLUDE_DIRS}
)

add_definitions(
    ${GTKMM_CFLAGS_OTHER}
    ${Boost_CFLAGS_OTHER}
)

add_executable(screen03 main.cpp)

target_link_libraries(
    screen03
    ${GTKMM_LIBRARIES}
    ${Boost_LIBRARIES}
)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
