# This is the 8th Sem Project of Sourav Sarkar, Tejas Dinkar and Thejaswi K

project(lblock)

find_package(Qt4 REQUIRED)
set(QT_USE_QTOPENGL true)
include(${QT_USE_FILE})

set (SOURCES main.cpp glbox.cpp drawobject.cpp item.cpp wall.cpp texture.cpp)

QT4_WRAP_CPP(SOURCES glbox.h)

add_executable(lblock ${SOURCES})
target_link_libraries(lblock ${QT_LIBRARIES})

add_custom_target (data ALL ${CMAKE_COMMAND} -E copy_directory
	${CMAKE_CURRENT_SOURCE_DIR}/data ${CMAKE_CURRENT_BINARY_DIR}/data )
