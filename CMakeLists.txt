# This is the 8th Sem Project of Sourav Sarkar, Tejas Dinkar and Thejaswi K

cmake_minimum_required(VERSION 2.6)
project(lblock)

find_package(Qt4 REQUIRED)
find_package(Doxygen)

set(QT_USE_QTOPENGL true)
set(QT_USE_QTXML true)
include(${QT_USE_FILE})

include_directories(${CMAKE_SOURCE_DIR} ${CMAKE_SOURCE_DIR}/ui ${CMAKE_SOURCE_DIR}/items)

add_subdirectory(ui)
add_subdirectory(items)

set (SOURCES main.cpp glbox.cpp drawobject.cpp texture.cpp item.cpp)

QT4_WRAP_CPP(SOURCES glbox.h)

add_executable(lblock ${SOURCES})
target_link_libraries(lblock ${QT_LIBRARIES} uilibrary itemslibrary)

if(DOXYGEN_FOUND)
	set(DOXY_CONFIG ${CMAKE_BINARY_DIR}/doxy.conf)
	configure_file(${CMAKE_SOURCE_DIR}/doxy.conf.in ${DOXY_CONFIG})
	message("Found Doxygen, Generating Documentation")
	add_custom_target(doc ${DOXYGEN_EXECUTABLE} ${DOXY_CONFIG})
	add_dependencies(lblock doc)
endif(DOXYGEN_FOUND)

add_custom_target (data ALL ${CMAKE_COMMAND} -E copy_directory
	${CMAKE_CURRENT_SOURCE_DIR}/data ${CMAKE_CURRENT_BINARY_DIR}/data )
