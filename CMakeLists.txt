cmake_minimum_required(VERSION 3.8)

project(DataFetcher)

if(NOT EXISTS "${CMAKE_BINARY_DIR}/conan.cmake")
   message(STATUS "Downloading conan.cmake from https://github.com/memsharded/cmake-conan")
   file(DOWNLOAD "https://raw.githubusercontent.com/conan-io/cmake-conan/master/conan.cmake"
                 "${CMAKE_BINARY_DIR}/conan.cmake")
endif()

include(${CMAKE_BINARY_DIR}/conan.cmake)

conan_cmake_run(CONANFILE conanfile.txt    #conanfile.py  # or relative build/conanfile.txt
                BASIC_SETUP UPDATE
		        BUILD missing)

if(CONAN_CMAKESUPPORT_ROOT)
	include("${CONAN_CMAKESUPPORT_ROOT}/cmake/support.cmake")
endif()

add_subdirectory(service)
#add_subdirectory(external)
