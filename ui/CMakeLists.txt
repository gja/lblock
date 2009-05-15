# This is the 8th Sem Project of Sourav Sarkar, Tejas Dinkar and Thejaswi K

include_directories(${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_BINARY_DIR})

QT4_WRAP_UI(UI_FILES mainwindow.ui)
QT4_WRAP_UI(UI_FILES textureswindow.ui)
QT4_WRAP_UI(UI_FILES edittexture.ui)
QT4_WRAP_UI(UI_FILES properties.ui)
QT4_WRAP_UI(UI_FILES itemproperties.ui)
QT4_WRAP_UI(UI_FILES addwindow.ui)

set (SOURCES mainwindow.cpp textureswindow.cpp textureslist.cpp
	texturesview.cpp edittexture.cpp properties.cpp floortopview.cpp
	lblockgraphicsitem.cpp itemproperties.cpp itempropertiesmodel.cpp
	itempropertiesview.cpp addwindow.cpp)
QT4_WRAP_CPP(SOURCES mainwindow.h textureswindow.h edittexture.h
	texturesview.h properties.h floortopview.h itemproperties.h
	itempropertiesmodel.h itempropertiesview.h addwindow.h)

add_library(ui ${SOURCES} ${UI_FILES})
target_link_libraries(ui ${QT_LIBRARIES})
