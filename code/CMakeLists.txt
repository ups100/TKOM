cmake_minimum_required (VERSION 2.6) 

#project name
project (TKOM) 

#look for boost library (required for this project)
FIND_PACKAGE( Boost REQUIRED )

#look for qt library (required for this project)
FIND_PACKAGE( Qt4 COMPONENTS QtNetwork QtSql REQUIRED )

#look for doxygen to make documentation
find_package(Doxygen REQUIRED)

INCLUDE( ${QT_USE_FILE} )
ADD_DEFINITIONS(${QT_DEFINITIONS})

SET(QT_DONT_USE_QTGUI TRUE)
SET(QT_USE_QTNETWORK TRUE)
SET(QT_USE_QTSQL 1)

#turn on automoc
SET(CMAKE_AUTOMOC TRUE)

SET( CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin )
SET( CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib )
SET( CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib )

set(CMAKE_EXE_LINKER_FLAGS "-lQtSql")
set(STATIC_LIBRARY_FLAGS "-lQtSql")

#subdirectories
add_subdirectory(Analyser)
add_subdirectory(Tokens)
add_subdirectory(Tests)
add_subdirectory(doxygen)
