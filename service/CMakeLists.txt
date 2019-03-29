
cmake_minimum_required(VERSION 3.8)

project(DataFetcher)

set(CMAKE_CXX_STANDARD 17)

include_directories(DataFetcher PUBLIC ${CMAKE_SOURCE_DIR}/service/include)

file(GLOB_RECURSE sources src/*)

add_executable(${PROJECT_NAME} ${sources})
target_link_libraries(${PROJECT_NAME} ${CONAN_LIBS})


