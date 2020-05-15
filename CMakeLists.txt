cmake_minimum_required(VERSION 3.4)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(
  HUNTER_CACHE_SERVERS
  "https://github.com/bmstu-iu8-cpp-sem-3/hunter-cache"
  CACHE STRING "Default cache server"
)

include("tools/gate/HunterGate.cmake")

HunterGate(
  URL "https://github.com/cpp-pm/hunter/archive/v0.23.218.tar.gz"
  SHA1 "9a3594a61227967fb92159339ba326701b287b19"
)


project(template)

string(APPEND CMAKE_CXX_FLAGS " -pedantic -Werror -Wall -Wextra")
string(APPEND CMAKE_CXX_FLAGS " -Wno-unused-command-line-argument")
string(APPEND CMAKE_CXX_FLAGS " -Wshadow -Wnon-virtual-dtor")

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

hunter_add_package(GTest)
find_package(GTest CONFIG REQUIRED)
hunter_add_package(Boost COMPONENTS filesystem program_options)
find_package(Boost CONFIG REQUIRED filesystem program_options)
hunter_add_package(OpenSSL)
find_package(OpenSSL REQUIRED)

hunter_add_package(gumbo)
find_package(gumbo CONFIG REQUIRED)

add_library(template STATIC
  ${CMAKE_CURRENT_SOURCE_DIR}/sources/source.cpp
)
add_executable(tests
  ${CMAKE_CURRENT_SOURCE_DIR}/tests/test.cpp
)

add_executable(main
        ${CMAKE_CURRENT_SOURCE_DIR}/sources/main.cpp
        )

target_include_directories(template 
  PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include
)
target_include_directories(tests 
  PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include
)
target_link_libraries(main template)
target_link_libraries(tests GTest::main template)
target_link_libraries(template gumbo::gumbo Boost::program_options OpenSSL::SSL)
enable_testing()
add_test(NAME unit_tests COMMAND tests) 
