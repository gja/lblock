# This is the 8th Sem Project of Sourav Sarkar, Tejas Dinkar and Thejaswi K

set (SOURCES lblockxmlengine.cpp lblockvalues.cpp)

add_library (xml ${SOURCES})
target_link_libraries(xml ${QT_LIBRARIES})
