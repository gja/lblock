# This is the 8th Sem Project of Sourav Sarkar, Tejas Dinkar and Thejaswi K

set (SOURCES wall.cpp table.cpp floor.cpp window.cpp )

add_library (items ${SOURCES})
target_link_libraries(items ${QT_LIBRARIES})
