
cmake_minimum_required(VERSION 2.6)

set(LOG2_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/log2 PARENT_SCOPE)

set(BOOST_EXTENSION_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/Boost.Extension PARENT_SCOPE)

set(TCLAP_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/tclap PARENT_SCOPE)

if(WIN32)
	add_subdirectory_with_bin(libantlr3c)
	set(LIBANTLR3C_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/libantlr3c/include PARENT_SCOPE)
endif()

set(ANTLR_BINARY ${CMAKE_CURRENT_SOURCE_DIR}/antlr-3.3.jar PARENT_SCOPE)

add_subdirectory_with_bin(libb64)
set(LIBB64_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/libb64/include PARENT_SCOPE)

add_subdirectory_with_bin(md5)
set(MD5_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/md5 PARENT_SCOPE)
